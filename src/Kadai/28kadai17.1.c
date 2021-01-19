/*
file name  :28kadai17.1.c
Producer   :Nishizawa Eiji
Description:skip table creation
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BM_TABLE_SIZE 256

void skiptable(int *table, const char *pattern, int ptn_len)
{
    /* パターンに無い文字はパターン文字列長をずらし幅にする */
    for (int i = 0; i < BM_TABLE_SIZE; i++)
    {
        table[i] = ptn_len;
    }
    /* パターンに含まれる文字のずらし幅を決定する */
    for (int i = 0; i < ptn_len; i++)
    {
        table[(int)pattern[i]] = ptn_len - i - 1;
    }
    /*表示*/
    printf("[table]  : default: step=%d\n", ptn_len);
    for (int i = 0; i < BM_TABLE_SIZE; i++)
    {
        if (table[i] != ptn_len)
            printf("         : char=%c: table[%03d]: step=%d\n",(char)i, i, (int)table[i]);
    }
}

int main()
{
    const char *pattern="television";//パターン
    int table[BM_TABLE_SIZE];//スキップテーブル
    int ptn_len = strlen(pattern);//パターンの長さ
    skiptable(table, pattern, ptn_len);

    return 0;
}
/*
実行結果
[table] : default: step=10
        : char=e: table[101]: step=6
        : char=i: table[105]: step=2
        : char=l: table[108]: step=7
        : char=n: table[110]: step=0
        : char=o: table[111]: step=1
        : char=s: table[115]: step=3
        : char=t: table[116]: step=9
        : char=v: table[118]: step=5
*/