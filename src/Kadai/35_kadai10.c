/*************************************
T3 35 西澤　英志
*************************************/
#include<stdio.h>

/*演習9-3*//*
#define num 10
int main(void)
{
	int i,j;
	char s[num][128];
	for(i=0;i<num;i++)
	{
		printf("s[%d]:",i);
		scanf("%s",s[i]);
		if(s[i][0]=='$'&&s[i][1]=='$'&&s[i][2]=='$'&&s[i][3]=='$'&&s[i][4]=='$')break;
	}
	for(j=0;j<i;j++)printf("s[%d]=\"%s\"\n",i,s[j]);
	
	return 0;
}*/
/*演習9-5*/
int str_char(const char s[],int c)
{

	for()
}
int main(void)
{
	char str[]="ABC\0DEF";
	printf("文字列strは\%s\です。\n",str);
	return 0;
}
