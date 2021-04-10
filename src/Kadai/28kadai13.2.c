/*
file name  :28kadai13.2.c
Producer   :
Description:Hash chain method
*/
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
struct cell *hash_search(char *key)
{
	struct cell *p;
	int h;
	h=hash(key);
	p=hashtbl[h];
	while(p!=NULL)
	{
		if(strcmp(key,p->key)==0)
			return p;
		else
			p=p->next;
	}
	return NULL;
}

int insert(char *key,char *data)
{
	struct cell *p;
	p=(struct cell*)malloc(sizeof(struct cell));
	strcpy(p->key,key);
	strcpy(p->data,data);	
	return hash_insert(p);
}
int delete(char *key)
{
	struct cell *p,*c=NULL;
	int h=hash(key);
	p=hashtbl[h];
	if(p==NULL)//データがなかった場合
		return -1;
	while(p!=NULL)
	{
		if(strcmp(key,p->key)==0)
		{
			if(c==NULL)//同じハッシュ値の先頭にあった場合
			{
				hashtbl[h]=p->next;
				hashtbl[h]=NULL;
			}
			else//先頭になかった場合
			{
				c->next=p->next;
				p=NULL;
			}
			return 0;
		}
		c=p;
		p=p->next;
	}
	return -1;
}

int main()
{
	char in_key[KEYL]; char in_data[DATAL],mode;
	struct cell *p;
	while(1)
	{
		printf("Please input mode:");
		scanf("%s",(char*)&mode);
		switch(mode)
		{
			case 'i':
			case 'I':
				printf("Input Key and data:");
				scanf("%s %s",in_key,in_data);
				int h=insert(in_key,in_data);
				printf("Hash=%d\n",h);
			break;
			case 's':
			case 'S':
				printf("Input Key:");
				scanf("%s",in_key);
				if((p=hash_search(in_key))!=NULL)
					printf("key %s,data %s\n",p->key,p->data);
				else
					printf("Error:No data\n");
			break;
			case 'd':
			case 'D':
				printf("Input Key:");
				scanf("%s",in_key);
				if(delete(in_key)!=-1)
					printf("delete data!\n");
				else
					printf("Error:No data\n");
			break;
			case 'Q':
			case 'q':
				printf("The end of the program\n");
				return 0;
			default:
				printf("Error:Non-existent command\n");
			break;
		}
	}	
	return 0;
}
/*
＜実行結果＞
f11@DESKTOP-0BFU86V:/mnt/c/Git/C-Programing/src/Kadai$ gcc -Wall 28kadai13.2.c
f11@DESKTOP-0BFU86V:/mnt/c/Git/C-Programing/src/Kadai$ ./a.out
Please input mode:i
Input Key and data:N ab
Hash=1
Please input mode:i
Input Key and data:BC abc
Hash=1
Please input mode:i
Input Key and data:qwe abcd
Hash=1
Please input mode:s
Input Key:N
key N,data ab
Please input mode:s
Input Key:BC
key BC,data abc
Please input mode:s
Input Key:qwe
key qwe,data abcd
Please input mode:d
Input Key:BC
delete data!
Please input mode:d
Input Key:qwe
delete data!
Please input mode:d
Input Key:N
delete data!
Please input mode:s
Input Key:N
Error:No data
Please input mode:s
Input Key:BC
Error:No data
Please input mode:s
Input Key:qwe
Error:No data
Please input mode:q
The end of the program
f11@DESKTOP-0BFU86V:/mnt/c/Git/C-Programing/src/Kadai$ 
*/
