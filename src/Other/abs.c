#include<stdio.h>
float abs(float x)
{
    if(x<0)
    {
        return x*-1;
    }
    else if(x>=0)
    {
        return x;
    }
}
int main(void)
{
    float num;
    printf("Type a number please\n");
    scanf("%f",&num);
    printf("num=%.2f,|num|=|%.2f|\n",num,abs(num));
    return 0;
}