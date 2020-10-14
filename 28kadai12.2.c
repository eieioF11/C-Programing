#include <stdio.h>
#include <string.h>
#include <malloc.h>

struct cell
{
	char key[10];
	int data[20];
	struct cell *next,*prev;
};
struct cell *root=NULL;

void enqueue(struct cell *r)
{
	struct  cell *p;
	if(root==NULL)
	{
		root=r;
		root->prev=NULL;
	}
	else
	{
		p=root;
		while(p->next!=NULL)
			p=p->next;
		r->prev=p;
		p->next=r;	
	}
	r->next=NULL;
	return;
}

struct cell *dequeue(char *key)
{
	struct cell *p;
	if(root==NULL)
		return NULL;
	p=root;
	while(strcmp(p->key,key))p=p->next;
	if(p->next==NULL&&p->prev==NULL)
		root=NULL;
	else if(p->next==NULL)
		p->prev->next=NULL;
	else if(p->prev==NULL)
	{
		root=p->next;
		root->prev=NULL;
	}
	else
	{
		p->prev->next=p->next;
		p->next->prev=p->prev;
	}
	return p;
}

int main()
{
	char in_key[10]; int in_data[20],mode;
	struct cell *p;
	while(1)
	{
		printf("Please input ENQ(E) or DEQ(D):");
		scanf("%s",(char*)&mode);
		switch(mode)
		{
			case 'E':
				printf("Input Key and data:");
				scanf("%s %s",in_key,(char*)in_data);
				p=(struct cell*)malloc(sizeof(struct cell));
				strcpy(p->key,in_key);
				strcpy((char*)p->data,(char*)in_data);
				enqueue(p);
			break;
			case 'D':
				printf("Input Key:");
				scanf("%s",in_key);
				p=dequeue(in_key);
				if(p!=NULL)
					printf("Key=%s,data=%s\n",p->key,(char*)p->data);
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
＜実行結果＞
eiji@DESKTOP-2RBKBSJ:/mnt/c/Users/Eiji Nishizawa/OneDrive/プログラム基礎課題$ gcc -Wall 28kadai12.2.c
eiji@DESKTOP-2RBKBSJ:/mnt/c/Users/Eiji Nishizawa/OneDrive/プログラム基礎課題$ ./a.out
Please input ENQ(E) or DEQ(D):E
Input Key and data:A abcd
Please input ENQ(E) or DEQ(D):E
Input Key and data:B bcde
Please input ENQ(E) or DEQ(D):E
Input Key and data:C cdef
Please input ENQ(E) or DEQ(D):D
Input Key:B
Key=B,data=bcde
Please input ENQ(E) or DEQ(D):D
Input Key:C
Key=C,data=cdef
Please input ENQ(E) or DEQ(D):D
Input Key:A
Key=A,data=abcd
Please input ENQ(E) or DEQ(D):D
Input Key:A
No data!
Please input ENQ(E) or DEQ(D):D
Input Key:B
No data!
Please input ENQ(E) or DEQ(D):D
Input Key:C
No data!
Please input ENQ(E) or DEQ(D):D
Input Key:d
No data!
Please input ENQ(E) or DEQ(D):q
eiji@DESKTOP-2RBKBSJ:/mnt/c/Users/Eiji Nishizawa/OneDrive/プログラム基礎課題$ 
*/
