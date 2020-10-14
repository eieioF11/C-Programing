/*************************************
    T3 35番　西澤　英志
*************************************/
#include<stdio.h>
/*演習10-1*//*

void adjust_point(int*n)
{
	if(*n>100)*n=100;
	else if(*n<0)*n=0;
}
int main(void)
{
	int num;
	printf("数値を入力して下さい\n");
	scanf("%d",&num);
	adjust_point(&num);
    	printf("%d\n",num);
    	return 0;
}*/
/*演習10-2*/

int uru(int*y)
{
	if((*y%4)==0)
	{
		if((*y%100)==0)
		{
			if((*y%400)==0)return 1;
		}
		else return 1;
	}
	return 0;
}

void decrement_data(int*y,int*m,int*d)
{
	if(*d==1)
	{
		if(*m==1){*m=12;*y-=1;}
		else *m-=1;
		switch(*m)
		{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:*d=31;break;
			case 4:
			case 6:
			case 9:
			case 11:*d=30;break;
			case 2:
				if(uru(y))*d=29;
				else *d=28;
				break;
		}
	}
	else *d-=1;
}
void increment_data(int*y,int*m,int*d)
{
	*d+=1;
	switch(*m)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:if(*d==32){*d=1;*m+=1;}break;
		case 4:
		case 6:
		case 9:
		case 11:if(*d==31){*d=1;*m+=1;}break;
		case 2:
			if((uru(y)&&*d==30)||(!uru(y)&&*d==29)){*d=1;*m+=1;}
			break;
	}
	if(*m==13){*m=1;*y+=1;}
}
int main(void)
{
	int y,m,d;
	printf("日付を入力して下さい\n");
	printf("年：");scanf("%d",&y);
	printf("月：");scanf("%d",&m);
	printf("日：");scanf("%d",&d);
	decrement_data(&y,&m,&d);
    	printf("decrement %d:%d:%d\n",y,m,d);
	increment_data(&y,&m,&d);
    	printf("increment %d:%d:%d\n",y,m,d);
    	return 0;
}
