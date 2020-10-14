/*************************************
    T3 35番　西澤　英志
*************************************/
#include<stdio.h>
/*演習10-4,5*/
void set_idx(int *v,int n)
{
	int i;
	for(i=0;i<n;i++)v[i]=i;
}

void ary_set(int v[],int n,int val)
{
	int i;
	for(i=0;i<n;i++)v[i]=val;
}

int main(void)
{
	const int num=10; 
	int data[num],i;
	/*演習10-4*/
	set_idx(data,num);
	printf("data[%d]={",num);
	for(i=0;i<num;i++)printf("%d,",data[i]);
	printf("}\n");
	/*演習10-5*/
	int a[]={1,2,3,4,5};
	ary_set(&a[2],2,99);
	for(i=0;i<5;i++)printf("a[%d] = %d\n",i,a[i]);
	/*配列aの要素数２から要素数３まで数が99に置き換わる*/
	return 0;
}
