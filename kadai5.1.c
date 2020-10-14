#include <stdio.h>

#define N 5//データ数
#define MAX 10

struct student
{
    int num;
    char name[10];
};

struct student St[MAX]=
{
   {3,"Sasaki"},
   {5,"Goto"},
   {8,"Hanada"},
   {10,"Toh"},
   {24,"Nishida"},
};

int search(int target)
{
    int hi,lo,mid;
    lo=0; hi=N-1;

    while(lo <= hi)
    {
        mid=(lo+hi)/2;//中央のデータのインデックス
        if(target==St[mid].num)       
            return mid;
        else if(target<St[mid].num)
            hi=mid-1;//左半分探索
        else
            lo=mid+1;//右半分探索
    }
    return -1;//見つからなかった
}

int main()
{
    int i;
    int tgt_key;
    while(1)
    {
        printf("Please input a key .\n");
        if(scanf("%d",&tgt_key)==EOF)
            break;
        if((i=search(tgt_key))!=-1)
            printf("Found! Num=%d,Name=%s \n",St[i].num,St[i].name);
        else
            printf("Not found.\n");
    }
    return 0;
}
/*
計算量のオーダー
線形探索
O(N)=O(5)
２分探索
O(log2(N))=O(log2(5))=O(2.3219...)≒O(2.32)
*/