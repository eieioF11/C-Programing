#include <Arduino.h>
#line 1 "c:\\Users\\eieio\\Dropbox\\office\\program\\Cprogram\\nabi1.cpp"
#line 1 "c:\\Users\\eieio\\Dropbox\\office\\program\\Cprogram\\nabi1.cpp"
#include <iostream>
#include <stdio.h>

int main()
{
    short x,y,k,datanum;
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
        if((coordinate[1][k]==coordinate[1][k+1])==1)
        {
            length++; 
        }
        else if(length==1) 
        {
            length=0;
        } 
        printf("length=%d\n",length);
    }
	return 0;
}
