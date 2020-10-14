#include<stdio.h>

int main()
{
	int d[10]={11,12,13,14,15,16,17,18,19,20};
	int *p=d;
	printf("%d\n",*p+1);//*p:d[0],*p+1:d[1].... 
	return 0;
}