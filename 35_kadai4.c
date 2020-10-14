#include<stdio.h>
#include<math.h>
/*演習7-9*/
int main(void)
{
    int a;
    printf("非負の整数を入力してください。\n");
    printf("面積 : ");scanf("%d",&a);
    printf("一辺の長さは%fです\n",sqrt((double)a));
    return 0;
}
/*演習7-4*/
int main(void)
{
    float a;
    double b;
    long double c;
    printf("非負の整数を入力してください。\n");
    printf("a : ");scanf("%f",&a);
    printf("b : ");scanf("%lf",&b);
    printf("c : ");scanf("%Lf",&c);
    printf("a   = %f\n",a);
    printf("b   = %f\n",b);
    printf("c   = %Lf\n",c);
    return 0;
}