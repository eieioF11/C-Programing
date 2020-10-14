/*************************************
	T3　西澤　英志
*************************************/
#include<stdio.h>

int strtoi(const char *s)
{
	int num=0,sign=1,index=1;
	if(*s=='+')
	{
		sign=1;
		s++;
	}
	if(*s=='-')
	{
		sign=-1;
		s++;
	}
	while(*s)
	{
		if(*s>='0'&&*s<='9')
		{
			num=num*index+(*s-'0');
			index=10;
		}
		s++;
	}
	return num*sign;
}


int main(void)
{
	char str[128];
	printf("文字列を入力してください:");
	scanf("%s",str);
	printf("%d\n",strtoi(str));

	return 0;
}
