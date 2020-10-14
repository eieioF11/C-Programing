#include<stadio.h>

#define N 100

int main(void )
{
    int max=0;
    int A[N];
    for(int i=0;i<N-1;i++)
    {
        if(A[i]>max)
            max=A[i];
    }
    printf("%d",max);
    return 0;
}