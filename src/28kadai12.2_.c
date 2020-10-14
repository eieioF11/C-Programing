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
	p=root;
	while(p->next!=NULL)
	{
		if(strcmp(p->key,key)==0)
		{
			if(p->next==NULL)
				p->prev->next=NULL;
			else if(p->prev==NULL)
			{
				root=p->next;
				root->next->prev=NULL;
			}
			else
			{
				p->prev->next=p->next;
				p->next->prev=p->prev;
			}
			return p;
			
		}
		p=p->next;
	}
	return NULL;
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
				printf("%s\n",p->key);
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

*/
