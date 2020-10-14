#include <stdio.h>
#include <string.h>
#include <malloc.h>
#define MAX 11
#define KEYL 4
#define DATAL 10
#define K 3


struct cell
{
	char key[KEYL];
	char data[DATAL];
	struct cell *next;
};
struct cell *hashtbl[MAX];

int hash(char p[])
{
	int i;
	int h=0;
	for(i=0;p[i]!='\0';i++)
		h=(h*K+p[i])%MAX;
	return h;
}

int hash_insert(struct cell *r)
{
	struct  cell *p;
	int h;
	h=hash(r->key);
	if(hashtbl[h]==NULL)
	{
		hashtbl[h]=r;
		r->next=NULL;
		return h;
	}
	else
	{
		p=hashtbl[h];
		while(1)
		{
			if(strcmp(r->key,p->key)==0)
				return -1;
			if(p->next==NULL)
				break;
			else
				p=p->next;
		}
		p->next=r;
		r->next=NULL;	
		return h;
	}
}

int insert(char *key,char *data)
{
	struct cell *p;
	p=(struct cell*)malloc(sizeof(struct cell));
	strcpy(p->key,key);
	strcpy(p->data,data);	
	return hash_insert(p);
}

int main()
{
	char in_key[KEYL]; char in_data[DATAL],mode;
	while(1)
	{
		printf("Please input mode:");
		scanf("%s",(char*)&mode);
		switch(mode)
		{
			case 'H':
				printf("Input Key and data:");
				scanf("%s %s",in_key,in_data);
				int h=insert(in_key,in_data);
				printf("Hash=%d\n",h);
			break;
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
[m17307@a717-pc014 T4]$ gcc -Wall  28kadai13.1.c
[m17307@a717-pc014 T4]$ ./a.out
Please input mode:H
Input Key and data:A abcd
Hash=10
Please input mode:H
Input Key and data:B cdef
Hash=0
Please input mode:q
[m17307@a717-pc014 T4]$ 

*/
