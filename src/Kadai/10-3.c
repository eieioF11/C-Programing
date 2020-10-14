#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define data 7

struct student
{
    char num[10];
    char name[10];
    int score;
};

void swap(struct student *x,struct student *y){
    struct student tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}

void quick_sort(struct student a[], int left, int right)
{
    int i,j,somewhere;
    struct student pivot;
    if(left >= right)
        return;
    somewhere = (left + right) / 2;
    pivot = a[somewhere];
    i = left; j = right;
    while(i <= j){
        while(a[i].score < pivot.score)
            i++;
        while(a[j].score > pivot.score)
            j--;
        if(i <= j)
        {
            swap(&a[i], &a[j]);
            i++; j--;
        }
    };
    quick_sort(a, left, j);
    quick_sort(a, i, right);
}

int main()
{
    char IN_num[10];
    char IN_name[20];
    int IN_score = 0, i = 0 ,total = 0;
    float ave = 0;
    struct student St[data];
    
    FILE *fp;
    if((fp=fopen("Student.txt","r"))==NULL)
        printf("ファイルを開けませんでした\n");
    else
    {
        while(fscanf(fp,"%s %s %d ",IN_num,IN_name,&IN_score)!=EOF)
        {
            strcpy(St[i].num, IN_num);
            strcpy(St[i].name, IN_name);
            St[i].score = IN_score;
            total = total + St[i].score;
            i++;
        }
    }
    fclose(fp);
    ave = total/data;
    printf("--------------------------\n");
    printf("ソート前\n");
    for(int i = 0; i < data; i++)
    {
        printf("%s %s %d\n",St[i].num, St[i].name, St[i].score);
    }
    
    quick_sort(St,0,data-1);
    printf("ソート後\n");
    for(int i = 0; i < data; i++)
    {
        printf("%s %s %d\n",St[i].num, St[i].name, St[i].score);
    }
    printf("--------------------------\n");
    printf("平均点   %f\n", ave);
    return 0;
}