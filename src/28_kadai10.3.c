#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 20
#define Swap(type,a,b) {type tmp; tmp=a;a=b;b=tmp;}

struct student
{
    char number[10];
    char name[20];
    int score;
};

int partition(struct student array[], int left, int right)
{
	int i,j,pivot;
	i=left;
	j=right+1;
	pivot=left;
	do
	{
		do{i++;}while(array[i].score < array[pivot].score);
		do{j--;}while(array[pivot].score < array[j].score);
		//pivotより小さいものを左へ，大きいものを右へ
		if(i<j){Swap(struct student,array[i],array[j]);}
	}while(i<j);
	Swap(struct student,array[pivot],array[j]);
	return j;
}
void quick_sort(struct student array[],int left,int right)
{
	int pivot;
	if(left<right)
	{
		pivot=partition(array,left,right);
		quick_sort(array,left,pivot-1);
		quick_sort(array,pivot+1,right);
	}
}


int main()
{
    char in_n[10];
    char in_name[20];
    int  in_score,sum=0;
    int i=0,j=0;

	struct student St[MAX];

	FILE *fp;
	if((fp = fopen("Student.txt","r"))==NULL)
	{
		printf("Error");
		exit(1);
	}
	while(fscanf(fp,"%s %s %d ",in_n,in_name,&in_score)!=EOF)
	{
		strcpy(St[i].number,in_n);
		strcpy(St[i].name,in_name);
		St[i].score=in_score;
		sum+=in_score;
		i++;
	}
	fclose(fp);
	/*
	for(j=0;j<i;j++)
		printf("%s %s %d\n",St[j].number,St[j].name,St[j].score);
	printf("%d\n\n",i);*/
			
	quick_sort(St,0,i-1);

	printf("-------------------------------------\n");
	for(j=i-1;j>=0;j--)
		printf("%s %s %d\n",St[j].number,St[j].name,St[j].score);
	printf("-------------------------------------\n");
	printf("平均点　%.1f\n",(float)sum/i);
    return 0;
}
/*
eiji@DESKTOP-FN2IOPH:/mnt/g/OneDrive/プログラム基礎課題$ ./a.out
-------------------------------------
TL0089 斎藤俊治 99
TL0070 山田太郎 95
TL0060 佐藤次郎 90
TL0013 吉田光子 80
TL0034 島田次子 78
TL0010 鈴木達郎 68
TL0012 後藤志郎 3
-------------------------------------
平均点　73.3
eiji@DESKTOP-FN2IOPH:/mnt/g/OneDrive/プログラム基礎課題$  
*/
