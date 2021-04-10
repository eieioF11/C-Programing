/*************************************
	T3 35　
*************************************/
#include<stdio.h>
/*演習8-6*/
int factorial(int n)
{
	int i,ans=n;
	for(i=n;i>1;i--)ans*=i-1;
	return ans;
}
int main(void)
{
	int n;
	printf("n=");scanf("%d",&n);
	printf("%d!=%d\n",n,factorial(n));
	return 0;
}
