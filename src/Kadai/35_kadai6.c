/*************************************
	T3 35番　
*************************************/
/*演習8-4*/
#include<stdio.h>

#define NUMBER 5

#define swap(x,y){int mem=x;x=y;y=mem;}

void bsort(int a[],int n) 
{
	int i,j;
	for(i=n-1;i>0;i--)//i n-1~0
	{
		for(j=0;j<i;j++)//j 0~i
		{
			if(a[j]>a[j+1])swap(a[j],a[j+1])//j番目の値のほうがその次の値より大きいとき入れ替える
		}
	}
	puts("\nSort completed");
} 


int main(void)
{
	int i;
	int data[NUMBER]={0};
	/*Input*/
	for(i=0;i<NUMBER;i++)
	{
		printf("%2d:",i+1);scanf("%d",&data[i]);
	}
	/*Calulation*/
	bsort(data,NUMBER);
	/*Output*/
	for(i=0;i<NUMBER;i++)printf("%2d:%d\n",i+1,data[i]);
	return 0;
}