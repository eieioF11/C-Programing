#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
void timer(int h,int m,int s)
{
	printf("timer%2d:%2d:%2dset\n",h,m,s );
	printf("start!\n");
	do//do while文
	{
		do
		{
			do
			{
				printf("%2d:%2d:%2d\n",h,m,s);
				usleep(1000000);
			}while(s!=0&&s--);
			if(m!=0)
			{
				s=59;
			}
		}while(m!=0&&m--);
		if(h!=0)
		{
			m=59;
		}	
	}while(h!=0&&h--);
	printf("finish!\n");
}
int main()
{
	int a,b,c;
	char on;
	while(1)
	{
		printf("Please select start or stop.\n");
		printf("start y/stop n \n");
		scanf("%c",&on);//charの場合%c　scanf("%□",&変数名);
		if(on=='n')
		{
			exit(0);//プログラム 終了
		}
		else if(on=='y')
		{
			printf("Please enter a number.\n");
			scanf("%d%d%d",&a,&b,&c);	
			if(a!=0||b!=0||c!=0)
			{	
				timer(a,b,c);
			}
		}
	}
	return 0;
}
