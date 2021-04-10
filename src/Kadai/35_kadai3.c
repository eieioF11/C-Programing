#include<stdio.h>
/*******************************************
 クラス　　  T3
 出席番号　　35
 名前 
********************************************/
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
/*演習7-4*/
unsigned set(unsigned x,int pos)
{
	unsigned ans;
	ans=x|1U<<(pos-1);
	return ans;	
}
unsigned reset(unsigned x,int pos)
{
	unsigned ans,inv;
	inv=~(1U<<(pos-1));
	ans=inv&x;
	return ans;
}
unsigned inverse(unsigned x,int pos)
{
	unsigned ans;
	ans=x^1U<<(pos-1);
	return ans;
}
/*演習7-5*/
unsigned set_n(unsigned x,int pos,int n)
{
	unsigned ans,mem;int i;
    mem=1U<<(pos-1);
    for(i=1;i<=(n-pos);i++)mem+=1U<<(pos-1+i);
	ans=x|mem;
	return ans;	
}
unsigned reset_n(unsigned x,int pos,int n)
{
	unsigned ans,inv,mem;int i;
    mem=1U<<(pos-1);
    for(i=1;i<=(n-pos);i++)mem+=1U<<(pos-1+i);
    inv=~mem;
	ans=inv&x;
	return ans;
}
unsigned inverse_n(unsigned x,int pos,int n)
{
	unsigned ans,mem;int i;
    mem=1U<<(pos-1);
    for(i=1;i<=(n-pos);i++)mem+=1U<<(pos-1+i);
	ans=x^mem;
	return ans;
}

int main(void)
{
    unsigned a,pos,n;
    printf("非負の整数を入力してください。\n");
    printf("a   : ");scanf("%u",&a);
    printf("pos : ");scanf("%u",&pos);
    printf("n   : ");scanf("%u",&n);
    printf("\na           = ");print_bits(a);
    printf("\nset         = ");print_bits(set(a,pos));
    printf("\nreset       = ");print_bits(reset(a,pos));
    printf("\ninverse     = ");print_bits(inverse(a,pos));
    printf("\nset_n       = ");print_bits(set_n(a,pos,n));
    printf("\nreset_n     = ");print_bits(reset_n(a,pos,n));
    printf("\ninverse_n   = ");print_bits(inverse_n(a,pos,n));
    putchar('\n');
    return 0;
}
/*
実行結果

非負の整数を入力してください。
a   : 515
pos : 1
n   : 11

a           = 00000000000000000000001000000011
set         = 00000000000000000000001000000011
reset       = 00000000000000000000001000000010
inverse     = 00000000000000000000001000000010
set_n       = 00000000000000000000011111111111
reset_n     = 00000000000000000000000000000000
inverse_n   = 00000000000000000000010111111100
*/
