/*************************************
	T3 35番　
*************************************/
/*演習7-11,8-1,8-2*/
#include<stdio.h>

#define diff(x,y) (x-y)
#define max(x,y) ( ( (x) > (y) )? (x): (y) )


int main(void)
{
    int i,a,b,c,d;
	float x,ans=0;
	
	printf("演習7-11\n");
	
	printf("List7-11");
	for(x=0.0;x<=1.0;x+=0.01)
		ans+=x;
	printf(" = %f\n",ans);

	printf("List7-12");
	ans=0;
	for(i=0;i<=100;i++)
		ans+=i/100.0;
	printf(" = %f\n",ans);
	
	printf("演習8-1\n");
	a=10;b=5;
	printf("x=%d,y=%d,x-y=%d\n",a,b,diff(a,b));
	
	printf("演習8-2\n");
	a=b=c=d=0;
	printf("a:");scanf("%d",&a);
	printf("b:");scanf("%d",&b);
	printf("c:");scanf("%d",&c);
	printf("d:");scanf("%d",&d);
	printf("max(max(%d,%d),max(%d,%d)) = %d\n",a,b,c,d,max(max(a,b),max(c,d)));
	printf("max(max(max(%d,%d),%d),%d) = %d\n",a,b,c,d,max(max(max(a,b),c),d));
	return 0;
}
/*

出力結果

演習7-11
List7-11 = 50.499985
List7-12 = 50.500004
演習8-1
x=10,y=5,x-y=5
演習8-2
a:2
b:3
c:4
d:1
max(max(2,3),max(4,1)) = 4
max(max(max(2,3),4),1) = 4

考察

演習7-11
誤差が蓄積するため異なる値が出力されたと考えた

演習8-2
max(max(a, b), max(c, d))); は、
((((((a) > (b)) ? (a) : (b)))) > ((((c) > (d) ? (c) : (d)))) ? ((((a) > (b)) ? (a) : (b))) : ((((c) > (d)) ? (c) : (d))));
max(max(max(a,b), c), d)); は、
((((((((a) > (b)) ? (a) : (b))) > (c) ? ((((a) > (b)) ? (a) : (b))) : (c))) > (d) ) ? ((((((a) > (b)) ? (a) : (b))) > (c) ? ((((a) > (b)) ? (a) : (b))) : (c))) : (d));
と展開される。
出力結果よりどちらも正しい値が出ていることがわかる。
*/
