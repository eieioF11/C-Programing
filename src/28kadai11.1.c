#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct student
{
	int num;
	char name[10];
	struct student *next;
};
struct student *root = NULL;

void enqueue(struct student *r)
{
	struct student *p;
	if(root==NULL)
		root=r;
	else
	{
		p=root;
		while(p->next!=NULL)
			p=p->next;
		p->next=r;
	}
	r->next=NULL;
	return;
}
struct student *dequeue()
{
	struct student *p;
	if(root==NULL)
		return NULL;
	p=root;
	root=p->next;
	return p;
}

int main()
{
	int in_num; char in_name[10],mode;
	struct student *p;
	while(1)
	{
		printf("Please input ENQ(E) or DEQ(D):");
		scanf("%s",&mode);
		switch(mode)
		{
			case 'E':
				printf("Input number and name:");
				scanf("%d %s",&in_num,in_name);
				p=(struct student*)malloc(sizeof(struct student));
				p->num=in_num;
				strcpy(p->name,in_name);
				enqueue(p);
			break;
			case 'D':
				p=dequeue();
				if(p!=NULL)
					printf("Number=%d,name=%s\n",p->num,p->name);
				else
					printf("No data!\n");
			break;
			case 'Q':
			case 'q':
				return 0;
			default:
				printf("error\n");
			break;
		}
	}	
	return 0;
}
/*
[m17307@a717-pc014 T4]$ gcc -Wall 28kadai11.1.c
[m17307@a717-pc014 T4]$ ./a.out
Please input ENQ(E) or DEQ(D):E
Input number and name:4 yamada
Please input ENQ(E) or DEQ(D):E
Input number and name:5 tanaka
Please input ENQ(E) or DEQ(D):D
Number=4,name=yamada
Please input ENQ(E) or DEQ(D):D
Number=5,name=tanaka
Please input ENQ(E) or DEQ(D):D
No data!
Please input ENQ(E) or DEQ(D):q

*/
