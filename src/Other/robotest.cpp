#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

#define ROBO_R 50
#define MS 0.001

class PID
{
private:
    float Kp, Ki, Kd, Min, Max;
    float integral;
    float past, deviation;
    float dt;

    unsigned long nowtime, oldtime;

public:
    PID(float Kp_, float Ki_, float Kd_, float Min_, float Max_, float dt_);
    PID(float Min_, float Max_, float dt_);
    void setgain(float Kp_, float Ki_, float Kd_);
    void setoutput(float Min, float Max);
    float output(float r, float y,float dt); //r,目標値　y,出力値    出力　Min~Maxの範囲で出力
    float output(float r, float y);
    void reset();                   //積分値の初期化
};
PID::PID(float Kp_, float Ki_, float Kd_, float Min_, float Max_, float dt_)
{
    Kp = Kp_;
    Ki = Ki_;
    Kd = Kd_;
    Min = Min_;
    Max = Max_;
    dt = dt_;
    reset();
    //printf("PID initialize!\n\rParameter(Kp=%.3f/Ki=%.3f/Kd=%.3f/Min=%.3f~Max=%.3f/Processing time = %.3f)\n\r",Kp,Ki,Kd,Min,Max,dt);
}
PID::PID(float Min_, float Max_, float dt_)
{
    Kp = Ki = Kd = 0.0;
    Min = Min_;
    Max = Max_;
    dt = dt_;
    reset();
    printf("Parameter set (Min=%.3f~Max=%.3f/Processing time = %.3f)\n\r", Min, Max, dt);
}
void PID::setgain(float Kp_, float Ki_, float Kd_)
{
    Kp = Kp_;
    Ki = Ki_;
    Kd = Kd_;
    reset();
    printf("Gain set (Kp=%.5f/Ki=%.5f/Kd=%.5f)\n\r", Kp, Ki, Kd);
}
void PID::setoutput(float Min, float Max)
{
    this->Min = Min;
    this->Max = Max;
}

float PID::output(float r, float y)
{
    float pid=output(r,y,this->dt);
    return pid;
}

float PID::output(float r, float y,float dt)
{
    past = deviation;
    deviation = r - y;                            //偏差
    integral += ((past + deviation) / 2) * dt;    //積分
    float differential = (deviation - past) / dt; //微分
    float pid = Kp * deviation + Ki * integral + Kd * differential;
    if (pid > Max)
        pid = Max;
    if (pid < Min)
        pid = Min;
    return pid;
}
void PID::reset()
{
    integral = 0.0;
    past = 0.0;
    deviation = 0.0;
    //printf("PID reset!\n\r");
}

struct cordinate
{
    double x;
    double y;
    double angle;
} r;

inline float mapfloat(float x, float in_min, float in_max, float out_min, float out_max)
{
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

long t, now, old;
double dt;

void move(double Vx, double Vy, double Angler)
{
    now = t;
    dt = (now - old);
    r.x += 2 * M_2_PI * ROBO_R * Vx * dt * MS;
    r.y += 2 * M_2_PI * ROBO_R * Vy * dt * MS;
    r.angle += 2 * M_2_PI * ROBO_R * Angler * dt * MS;
    old = now;
}

PID pid(0.15,0.00001,0,-1,1,1);
double v, a, x, dif;
double dd, sd,hdd;
double dir;
void Trmove(double X, double V, double A)
{
    v = V;
    a = A;
    x = X;
    float dif = X - r.x;
    dir = (dif > 0) ? 1 : -1;
    dd = abs(dif) / 3;
    hdd=dd/2;
    sd = r.x;
    //printf("%f\n\r",dd);
}
int count;
void update(double *Vx, double *Vy, double *Angler)
{
    float DIF=0;
    switch (count)
    {
    case 0:
        *Vx += a / (2 * M_2_PI * ROBO_R) * dir;
        if (abs(*Vx) >= v || abs(r.x - sd) > dd)
        {
            *Vx=v*dir;
            count = 2;
        }
        break;
    case 1:
        if (abs(r.x - sd) > 2 * dd+hdd)
        {
            dif = abs(x - r.x);
            count = 2;
        }
        break;
    case 2:
        DIF=(double)pid.output(x,r.x,dt);
        *Vx = DIF * v;
        //DIF=x - r.x;
        //*Vx = mapfloat(abs(DIF), 0, dif, 0, v) * dir;
        break;
    default:
        count = 0;
        break;
    };
}

const int px = 10;
int main(void)
{
    r.x = 100;
    double Vx = 0, Vy = 0, Angler = 0;
    Trmove(px, 5, 10);
    while (true)
    {
        update(&Vx, &Vy, &Angler);
        move(Vx, Vy, Angler);
        printf("%5ld,%f,%f,%f,%f,%f,%f,%f\n", t, r.x, r.y, r.angle, Vx, Vy, Angler,pid.output(x,r.x,dt));
        t++;
        //usleep(1000000);//1[s]
        //usleep(1000);//1[s]
        if (abs(px - r.x) <= 0.0000001)
            break;
    }
    return 0;
}