#include<stdio.h>

float calc(char op,float a,float b)
{
    switch(op)
    {
        case '+':return a+b;
        case '-':return a-b;
        case '*':return a*b;
        case '/':return a/b;
        default: return 0;
    }
}

int main(void)
{
    char op[5]={'+','-','*','/','a'};
    for(int i=0;i<5;i++)
        printf("%c %f\n",op[i],calc(op[i],10,5));//check
    return 0;
}