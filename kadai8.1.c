#include <stdio.h>

struct student
{
    int num;
    char name[20];
    int score;
};
struct student st[]=
{
    {3,"鈴木三郎",86},
    {1,"山田一郎",75},
    {14,"高橋十四子",93},
    {2,"田中二子",68},
};
int main()
{
    FILE* fp;
    if((fp=fopen("student_out.txt","w"))==NULL)
    {
        printf("file dose not open!");
        return -1;
    }
    int i;
    for(i=0;i<4;i++)
        fprintf(fp,"%d %s %d\n",st[i].num,st[i].name,st[i].score);
    fclose(fp);
    return 0;
}