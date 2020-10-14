#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void Trapezoidal(double *v,double r,double v_)//Trapezoidal control
{
    if(r<v_*-1)
    {
        if(*v<r&&r>0)*v+=1.0;
        if(*v>r&&r<0) *v-=1.0;
    }
    else if(r>v_)
    {
        if(*v<r&&r>0)*v+=1.0;
        if(*v>r&&r<0) *v-=1.0;
    }
    else *v=r;
}
int main(void)
{
    double Vx=0,Vy=0,rx=0,ry=0;
    scanf("%lf",&rx);
    scanf("%lf",&ry);
    while(true)
    {
        Trapezoidal(&Vx,rx,3);
        Trapezoidal(&Vy,ry,3);
        printf("%f,%f\n",Vx,Vy);
        usleep(1000000);
    }
    return 0;
}