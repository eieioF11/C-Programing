/*************************************
	T3　西澤　英志
*************************************/
#include<stdio.h>

#define NAME_LEN 64

struct student
{
    char name[NAME_LEN];
    int height;
    float weight;
    long schols;
};


int main(void)
{
    struct student takao = {"Takao",173,86,2};
    printf("name   %p\nheight %p\nweight %p\nschols %p\n",takao.name,&takao.height,&takao.weight,&takao.schols);
	return 0;
}
