/*************************************
T3 35 
*************************************/
#include<stdio.h>

/*演習8-10*/
int main(void)
{
	int ch,i,j;
	int cut[10]={0};
	while((ch=getchar())!=EOF)
	{
		if(ch>='0'&&ch<='9')
			cut[ch-'0']++;
	}
	printf("入力された数字の回数は\n");
	for(i=0;i<10;i++)
	{
		printf("%d ",i);
		for(j=0;j<cut[i];j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}

/*演習9-1*/
int main(void)
{
	char str[]="ABC\0DEF";
	printf("文字列strは/%s/です。\n",str);
	return 0;
}
/* 
考察
実行結果がABCしか表示されなかったのは\0が文字列の終わりを意味するものなので\0以降のDEFは表示されなかったと考えた
*/

/*演習9-2*/
int main(void)
{
	char s[]="ABC";
	printf("文字列sは/%s/です。\n",s);
	*s='\0';
	printf("文字列sは/%s/です。\n",s);
	return 0;
}
