/*************************************
	T3　
*************************************/
#include<time.h>
#include<stdio.h>

int upper(int c){
    if('a' <= c && c <= 'z'){
        c = c - ('a' - 'A');
    }
    return c;
}

int main(void)
{
	int ch;
	FILE *sfp;
	FILE *dfp;
	char sname[FILENAME_MAX];
	char dname[FILENAME_MAX];
	/*13-8*/	
	printf("ファイル名：");scanf("%s",sname);
	printf("コピー先ファイル名：");scanf("%s",dname);
	
	printf("\n");
	
	if((sfp = fopen(sname,"r")) == NULL)
		printf("\aファイルをオープンできません。\n");
	else
	{
		if((dfp = fopen(dname,"w")) == NULL)
			printf("\aファイルをオープンできません。\n");
		else
		{
			while((ch = fgetc(sfp)) != EOF)
			{
				fputc(ch,dfp);
				putchar(ch);
			}
			fclose(dfp);
		}
		fclose(sfp);
	}
	/*13-9*/
	printf("ファイル名：");scanf("%s",sname);
	printf("コピー先ファイル名：");scanf("%s",dname);
	
	printf("\n");
	
	if((sfp = fopen(sname,"r")) == NULL)
		printf("\aファイルをオープンできません。\n");
	else
	{
		if((dfp = fopen(dname,"w")) == NULL)
			printf("\aファイルをオープンできません。\n");
		else
		{
			while((ch = fgetc(sfp)) != EOF)
			{
				fputc(upper(ch),dfp);
				putchar(upper(ch));
			}
			fclose(dfp);
		}
	}
	/*13-11*/
	const int n=10;
	double ddata[n]={0};//{0.0,0.01,0.123,0.0123,0.515,0.121,0.432,0.432,0.432,0.432};
	printf("ファイル名：");scanf("%s",sname);
	
	printf("\n");
	
	if((sfp = fopen(sname,"wb")) == NULL)
		printf("\aファイルをオープンできません。\n");
	else
	{
		fwrite(ddata,sizeof(double),n,sfp);
		fclose(sfp);
	}

	if((sfp = fopen(sname,"rb")) == NULL)
		printf("\aファイルをオープンできません。\n");
	else
	{
		fread(ddata,sizeof(double),n,sfp);
		int i;
		for(i=0;i<n;i++)
		{
			printf("%f\n",ddata[i]);
		}
		fclose(sfp);	
	}
	return 0;
}
