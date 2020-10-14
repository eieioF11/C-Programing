#include <stdio.h>

union UNI_TEST_T
{
    float a;
    char b[4];
} test;

int main(void)
{
    test.a=3.141592;
    printf("%f\n\r",test.a);
    printf("%d,%d,%d,%d\n\r",test.b[0],test.b[1],test.b[2],test.b[3]);
    printf("%f\n\r",test.b[0]+test.b[1]+test.b[2]+test.b[3]);
    return 0;
}