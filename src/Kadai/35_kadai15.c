/*************************************
	T3　
*************************************/
#include<stdio.h>
#include<ctype.h>
/*11-4*/
void put_string(const char *s)
{
	printf("%s",s);
}
/*11-5*/
int str_chnum(const char *s,int c)
{
	int len=0;
	while(*(s+len))
	{
		if(*(s+len)==c)
			return len+1;
		len++;
	}
	return 0;
}
/*11-6*/
char *str_chr(const char *s,int c)
{
	int len=0;
	while(*(s++))
	{
		if(*s==c)
			return (char*)s;
		len++;
	}	
	return NULL;
}
/*11-7*/
void str_toupper(char *s)
{
	int i = 0;
	while(*(s+i))
	{
		*(s+i)=toupper(*(s+i));
		i++;
	}
}
void str_tolower(char *s)
{
	int i = 0;
	while(*(s+i))
	{
		*(s+i)=tolower(*(s+i));
		i++;
	}
}
/*11-8*/
void del_digit(char *str)
{
	int i=0,j=0;
	while(*(str+i))
	{
		if(*(str+i)>='0'&&*(str+i)<='9'){}
		else
		{
			*(str+j)=*(str+i);
			j++;
		}
		i++;
	}	
	*(str+j)='\0';
}

int main(void)
{
	char str[128];
	char c='d';
	printf("11-4\n");
	printf("文字列を入力してください:");
	scanf("%s",str);
	put_string(str);
	
	printf("\n11-5\n");
	printf("文字 %c\n",c);
	printf("%d\n",str_chnum(str,c));
	
	printf("11-6\n");
	char *ans=str_chr(str,c);
	printf("ans=%p\n",ans);
	
	printf("11-7\n");
	printf("文字列を入力してください:");
	scanf("%s",str);
	str_toupper(str);
	printf("大文字：%s\n",str);
	str_tolower(str);
	printf("小文字：%s\n",str);
	
	printf("11-8\n");
	printf("文字列を入力して下さい:");
	scanf("%s",str);
	del_digit(str);
    	printf("%s\n",str);
	return 0;
}
