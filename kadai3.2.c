#include <stdio.h>

#define num 5

struct book
{
    char title[50];
    char author[20];
    unsigned int price;
};

int main()
{
    struct book BOOK[num]=
        {
        {"アルゴリズムとデータ構造","森本",2600},
        {"明解c言語"               ,"柴田",1000},
        {"コンピュータネットワーク","齋藤",3000},
        {"新微分積分"              ,"中谷",1500},
        {"新基礎数学"              ,"斎藤",1100},
        };
    int i;
    for(i=0;i<num;i++)
        printf("%s/%s ￥%d\n",BOOK[i].title,BOOK[i].author,BOOK[i].price);
    return 0;
}