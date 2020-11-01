#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <time.h>
#include <math.h>

#define ROBO_R 50
#define MS 0.001

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

long t,now,old;

void move(double Vx,double Vy,double Angler)
{
    now=t;
    double dt=(now-old);
    r.x+=2*M_2_PI*ROBO_R*Vx*dt*MS;
    r.y+=2*M_2_PI*ROBO_R*Vy*dt*MS;
    r.angle+=2*M_2_PI*ROBO_R*Angler*dt*MS;
    old=now;
}

double v,a,x,dif;
double dd,sd;
void Trmove(double X,double V,double A)
{
    v=V;
    a=A;
    x=X;
    dd=X/3;
    sd=r.x;
    //printf("%f\n\r",dd);
}
int count;
void update(double *Vx,double *Vy,double *Angler)
{

    switch(count)
    {
        case 0:
            *Vx+=a/(2*M_2_PI*ROBO_R);
            if(*Vx>=v||(r.x-sd)>dd)
            {
                count=1;
            }
        break;
        case 1:
            if((r.x-sd)>2*dd)
            {
                count=2;
                dif=x-r.x;
                count=2;
            }
        break;
        case 2:
            *Vx=mapfloat(x-r.x,0,dif,0,v);
        break;
        default:
            count=0;
        break;
    };
}

const int px=100;
int main(void)
{
    double Vx=0,Vy=0,Angler=0;
    Trmove(px,5,10);
    while(true)
    {
        update(&Vx,&Vy,&Angler);
        move(Vx,Vy,Angler);
        printf("%5ld,%f,%f,%f,%f,%f,%f\n",t,r.x,r.y,r.angle,Vx,Vy,Angler);
        t++;
        //usleep(1000000);//1[s]
        if(px-r.x<=0.0000001)
            break;
    }
    return 0;
}