#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 20

struct student
{
    int num;
    char name[20];
    int score;
} st[MAX];

int main()
{
    FILE* fp;
    int i=0,j=0;
    int in_num=0;
    char in_name[20];

    if((fp=fopen("A.txt","r"))==NULL)
    {
        printf("file dose not open!");
        return -1;
    }

    while(fscanf(fp,"%d %s",&in_num,in_name)!=EOF)
    {
        st[i].num=in_num;
        strcpy(st[i].name,in_name);
        i++;
    }
    
    printf("点数を入力してください\n");
    for(j=0;j<i;j++)
    {
        printf("%s:",st[j].name);
        scanf("%d",&st[j].score);
    }
    fclose(fp);

    if((fp=fopen("B.txt","w"))==NULL)
    {
        printf("file dose not open!");
        return -1;
    }    
    for(i=0;i<4;i++)
        fprintf(fp,"%d %s %d\n",st[i].num,st[i].name,st[i].score);
    fclose(fp);
    return 0;
}