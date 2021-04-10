/*************************************
T3 35
*************************************/
#include<stdio.h>

/*演習8-7*//*
int combination(int n,int r)
{
	if(r==0||n==r)return 1;
	else if(r==1)return n;
	else return combination(n-1,r-1)+combination(n-1,r);
}
int main(void)
{
	int n,r;
	printf("n=");scanf("%d",&n);
	printf("r=");scanf("%d",&r);
	printf("%d C %d=%d\n",n,r,combination(n,r));
	return 0;
}
/*演習8-9*//*
int main(void)
{
	int ch;
	int cut=0;
	while((ch=getchar())!=EOF)
	{
		if(ch=='\n')
			cut++;
	}
	printf("標準入力に現れた回数は%dです\n",cut);
	return 0;
}*/
