#include <iostream>
#include <stdio.h>

int main()
{
    short x,y,k,datanum,start,end;
    int map[10][10]={
    {0,1,0,0,0,0,0,0,0,0},
    {0,1,1,1,1,1,1,1,1,0},
    {0,1,0,0,1,0,0,0,1,0},
    {0,1,0,0,1,0,0,0,1,0},
    {0,1,1,1,1,1,1,1,1,0},
    {0,1,0,0,1,0,0,0,1,0},
    {0,1,0,0,1,0,0,0,1,0},
    {0,1,1,1,1,1,1,1,1,0},
    {0,1,0,0,0,0,0,0,1,0},
    {0,1,0,0,0,0,0,0,1,0}},length;
    for(y=0;y<10;y++)
    {
        for(x=0;x<10;x++)
        {
            if(map[y][x]==1)
                k++;
        }
    }
    int coordinate[2][k];
    datanum=k;
    k=0;
    for(y=0;y<10;y++)
    {
        for(x=0;x<10;x++)
        {
            if(map[y][x]==1)
            {
                coordinate[0][k]=x;coordinate[1][k]=y;
                printf("(%d,%d)",coordinate[0][k],coordinate[1][k]);
                k++;
            } 
            else
                printf("　　 ");                          
        }
        printf("\n");
    }
    for(k=0;k<datanum;k++)
    {
        if(((coordinate[1][k]==coordinate[1][k-1])||(coordinate[1][k]==coordinate[1][k+1]))&&((coordinate[0][k]==coordinate[0][k-1]+1)||(coordinate[0][k]==coordinate[0][k+1]-1)))
        {
            length++; 
        }
        else if(coordinate[1][k]!=coordinate[1][k+1]&&length!=0)
        {
        	start=k-length;
            end=k;
            printf("s(%d,%d),e(%d,%d),length=%d\n",coordinate[0][start],coordinate[1][start],coordinate[0][end],coordinate[1][end],length);
            length=0;
        }
        else if(length==1) 
        {
            length=0;
        } 
    }
	return 0;
}