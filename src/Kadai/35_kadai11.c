/*************************************
    T3 35番　
*************************************/
/*演習9-9*/
#include<stdio.h>
/*
//演習9-9
#define swap(x,y){char mem=x;x=y;y=mem;}
 
void rev_string(char s[]) 
{
	int i=0,j=0;
	while(s[i])
		i++;
	for(j=0;j<(i/2);j++)
		swap(s[j],s[(i-j)-1]);
} 
int main(void)
{
	char s[128];
	printf("文字列を入力して下さい\n");
	scanf("%s",s);
	rev_string(s);
    	printf("%s\n",s);
    	return 0;
}*/
void del_digit(char s[])
{
	int i=0,j=0;
	while(s[i])
	{
		if(s[i]>='0'&&s[i]<='9')
		{
		}
		else
		{
			s[j]=s[i];
			j++;
		}
		i++;
	}
}
int main(void)
{
	char s[128];
	printf("文字列を入力して下さい\n");
	scanf("%s",s);
	del_digit(s);
    	printf("%s\n",s);
    	return 0;
}
