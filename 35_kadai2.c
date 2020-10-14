/*List 7-6*/
#include<stdio.h>

int count_bits(unsigned x)
{
	int bits = 0;
	while(x)
	{
		if(x&1U)bits++;
		x>>=1;
	}
	return bits;
}
int int_bits(void)
{
	return count_bits(~0U);
}
void print_bits(unsigned x)
{
	int i;
	for (i=int_bits()-1;i>=0;i--)
		putchar(((x>>i)& 1U)?'1':'0');
}
int main(void)
{
	unsigned a,b;
	printf("非負の整数を二つ入力してください。\n");
	printf("a : ");scanf("%u",&a);
	printf("b : ");scanf("%u",&b);
	printf("\na     = ");print_bits(a);
	printf("\nb     = ");print_bits(b);
	printf("\na & b = ");print_bits(a&b);
	printf("\na | b = ");print_bits(a|b);
	printf("\na ^ b = ");print_bits(a^b);
	printf("\n~a    = ");print_bits(~a);
	printf("\n~b    = ");print_bits(~b);
	putchar('\n');
	return 0;
}
/*
実行結果
非負の整数を二つ入力してください。
a : 11
b : 515

a     = 00000000000000000000000000001011
b     = 00000000000000000000001000000011
a & b = 00000000000000000000000000000011
a | b = 00000000000000000000001000001011
a ^ b = 00000000000000000000001000001000
~a    = 11111111111111111111111111110100
~b    = 11111111111111111111110111111100
*/

/*演習　7-2*/
#include<stdio.h>

int count_bits(unsigned x)
{
	int bits = 0;
	while(x)
	{
		if(x&1U)bits++;
		x>>=1;
	}
	return bits;
}
int int_bits(void)
{
	return count_bits(~0U);
}
void print_bits(unsigned x)
{
	int i;
	for (i=int_bits()-1;i>=0;i--)
		putchar(((x>>i)& 1U)?'1':'0');
}
int main(void)
{
	unsigned a,ans=0;
	int sift=0,mode=0;
	printf("非負の整数を入力してください。");scanf("%u",&a);
	printf("シフトする方向を入力してください(右の場合は0/左の場合は1)");scanf("%d",&mode);
	if(mode==0||mode==1)
	{
		printf("シフトするビット数を入力して下さい　");scanf("%d",&sift);
		printf("\n入力された数字の二進数は");print_bits(a);printf("です\n");
		printf("%dを%dビット",a,sift);
		if(mode==0)
		{
			printf("右に");
			ans=a>>sift;
		}
		else if(mode==1)
		{
			printf("左に");
			ans=a<<sift;
		}
		printf("シフトした値は%dでその値の二進数は",ans);print_bits(ans);printf("です\n");
		putchar('\n');
	}
	else printf("error\n");
	return 0;
}
/*
実行結果　右シフトの場合

非負の整数を入力してください。640
シフトする方向を入力してください(右の場合は0/左の場合は1)0
シフトするビット数を入力して下さい　2

入力された数字の二進数は00000000000000000000001010000000です
640を2ビット右にシフトした値は160でその値の二進数は00000000000000000000000010100000です

実行結果　左シフトの場合

非負の整数を入力してください。640
シフトする方向を入力してください(右の場合は0/左の場合は1)1
シフトするビット数を入力して下さい　2

入力された数字の二進数は00000000000000000000001010000000です
640を2ビット左にシフトした値は2560でその値の二進数は00000000000000000000101000000000です
*/