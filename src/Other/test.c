#include<stdio.h>

void sine(int *point){
    int n1,n2;
    scanf("%d%d",&n1,&n2);
    *point=n1+n2;
    *(point+1)=n1-n2;
    *(point+2)=n1*n2;
    *(point+3)=n1/n2;
}


int main()
{
    int num[4];
    sine(num);
    printf("%d,%d,%d,%d\n",num[0],num[1],num[2],num[3]);
	return 0;
}