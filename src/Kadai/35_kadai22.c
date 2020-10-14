/*************************************
	T3　西澤　英志
*************************************/
#include<stdio.h>

typedef struct
{
	char name[100];
	double weight;
	double height;	
} People;

void swap(People *x,People *y)
{
	People temp = *x;
	*x=*y;
	*y=temp;
}

int main(void)
{
	FILE *fp;
	int ninzu = 0;
	People p[10];
	double hsum = 0.0;
	double wsum = 0.0;
	int i,j;
	//13-3
	if((fp = fopen("hw.dat","r"))==NULL)
		printf("\aファイルをオープンできません。\n");
	else
	{
		while (fscanf(fp,"%s%lf%lf",p[ninzu].name,&p[ninzu].height,&p[ninzu].weight) == 3)
		{
			//printf("%-10s %5.1f %5.1f\n",name,height[ninzu],weight);
			ninzu++;
			hsum+=p[ninzu].height;
			wsum+=p[ninzu].weight;
		}
		
		for(i=0;i<ninzu-1;i++)
		{
			for(j=ninzu-1;j>i;j--)
			{
				if(p[j-1].height>p[j].height)
					swap(&p[j-1],&p[j]);
			}
		}
		for(i=0;i<ninzu-1;i++)printf("%d %-10s %5.1f %5.1f\n",i,p[i].name,p[i].height,p[i].weight);
		printf("-----------------------------------\n");
		printf("Ave %5.1f %5.1f\n",hsum/ninzu,wsum/ninzu);
		fclose(fp);
	}	
	
	//13-4
	if((fp = fopen("hw2.dat","w"))==NULL)
		printf("\aファイルをオープンできません。\n");
	else
	{
		printf("num:");scanf("%d",&ninzu);
		while(ninzu)
		{
			printf("name:");scanf("%s",p[0].name);
			printf("height:");scanf("%lf",&p[0].height);
			printf("weight:");scanf("%lf",&p[0].weight);
			fprintf(fp,"%s %f %f\n",p[0].name,p[0].height,p[0].weight);
			ninzu--;
		}
		fclose(fp);
	}
	
	return 0;
}
