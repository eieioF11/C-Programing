#include <stdio.h>

struct student
{
    int num;
    char name[10];
    int score;
};

void Swap(struct student a,struct student b)
{   
    struct student tmp;
    tmp=a;
    a=b;
    b=tmp;
}

void sort(struct student st[],int n)
{
    for()
    {
        for()
        {
            
        }
    }
}

int main()
{
    struct student St[]=
    {
        {1,"Ichi",90},
        {2,"Ni",70},
        {3,"San",80},
        {4,"Yon",40},
        {5,"Go",60},
        {6,"Roku",80},
        {7,"Nana",20},
        {8,"Hati",90},
        {9,"Que",10}
    }

    return 0;
}