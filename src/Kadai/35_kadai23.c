/*************************************
	T3　西澤　英志
*************************************/
#include<time.h>
#include<stdio.h>

const char data_file[] = "datetime.dat";

void get_data(void)
{
	FILE *fp;
	if((fp = fopen(data_file,"r")) == NULL)
		printf("本プログラムを実行するのは初めてですね。\n");
	else
	{
		char feeling[100];
		int year,month,day,h,m,s;
		fscanf(fp,"%d%d%d%d%d%d%s\n",&year,&month,&day,&h,&m,&s,feeling);
		printf("前回は%d年%d月%d日%d時%d分%d秒で、気分は%sでした。\n",year,month,day,h,m,s,feeling);
		fclose(fp);
	}
}

void put_data(void)
{
	FILE *fp;
	time_t current = time(NULL);
	struct tm *timer = localtime(&current);
	if((fp = fopen(data_file,"w")) == NULL)
		printf("ファイルをオープンできません。\n");
	else
	{
		char feeling[100];
		printf("現在の気分は：");scanf("%s",feeling);
		fprintf(fp,"%d %d %d %d %d %d %s\n",timer->tm_year+1900,timer->tm_mon+1,timer->tm_mday,timer->tm_hour,timer->tm_min,timer->tm_sec,feeling);
		fclose(fp);
	}
}

int main(void)
{
	/*13-5*/
	get_data();
	put_data();
	/*13-6*/
	int ch;
	int count=0;
	FILE *fp;
	char fname[FILENAME_MAX];
	
	printf("ファイル名：");
	scanf("%s",fname);
	
	if((fp = fopen(fname,"r")) == NULL)
		printf("\aファイルをオープンできません。\n");
	else
	{
		while((ch = fgetc(fp)) != EOF)
		{
			if(ch =='\n')count++;
		}
		fclose(fp);
		printf("%sの中身の改行回数は%d回です。\n",fname,count);
	}
	/*13-7*/
	count=0;
	printf("ファイル名：");
	scanf("%s",fname);
	
	if((fp = fopen(fname,"r")) == NULL)
		printf("\aファイルをオープンできません。\n");
	else
	{
		while((ch = fgetc(fp)) != EOF)
		{
			if('0' <= ch && ch <= '9')count++;
		}
		fclose(fp);
		printf("%sの中身の改行回数は%d回です。\n",fname,count);
	}
	return 0;
}
