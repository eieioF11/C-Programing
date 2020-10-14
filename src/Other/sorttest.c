#include<stdio.h>

void printArray(int a[],int n)
{
    for(int i=0;i<n;i++)
        printf("%d,",a[i]);
    printf("\n");
}

void ins_sort(int a[],int n)
{
    int i,j,x;
    for(i=1;i<n;i++)
    {
        x=a[i];
        for(j=i-1;j>=0 && a[j]>x;j--)
        {
            a[j+1]=a[j];
            //printArray(a,n);
            printf(" %d\n",x);
        }
        a[j+1]=x;
        printArray(a,n);
    }
}
int main(void)
{   
    int a[4]={2,3,2,1};
    ins_sort(a,4);
    return 0;
}