#include<stdio.h>

int fib(int n)
{
    if(n==1||n==2)
        return 1;
    else
        return fib(n-2)+fib(n-1);
}

int main(void)
{
    printf("%d\n",fib(10));//check
    printf("%lf\n",(double)fib(45)/(double)fib(44));//check
    return 0;
}