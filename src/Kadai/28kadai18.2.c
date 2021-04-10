/*
file name  :28kadai18.2.c
Producer   :
Description:
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define cget() C=getchar()
#define NUM 'N'
#define LPAR '('
#define RPAR ')'
#define PLUS '+'
#define MINUS '-'
#define MUL '*'
#define DIV '/'

char C=' ';
float Value;

char get_token()
{
    int i;
    char token;

    while(C==' ' || C=='\t' || C=='\n')
        cget();
    if(C==EOF)
        return(EOF);
    if(C>='0' && C<='9')
    {
        Value=(C-'0');
        cget();
        while(C>='0' && C<='9')
        {
            Value=10.0*Value+(C-'0');
            cget();
        }
        if(C=='.')
        {
            cget();
            i=10;
            while(C>='0' && C<='9')
            {
                Value=Value+(float)(C-'0')/i;
                i*=10;
                cget();
            }
        }
        return(NUM);
    }
    switch(C)
    {
        case '(':token=LPAR;break;
        case ')':token=RPAR;break;
        case '+':token=PLUS;break;
        case '-':token=MINUS;break;
        case '*':token=MUL;break;
        case '/':token=DIV;break;
    }
    cget();
    return(token);
}


int main()
{
    while(1)
    {
        char token = get_token();
        if(token==EOF)
            break;
        else if(token!='N')
            printf("%c ",token);
        else
            printf("%.2f ",Value);
    }
    printf("\nEND\n");
    return 0;
}
/*
Ctrl + D　で終了
実行結果
f11@DESKTOP-F11:/mnt/c/Git/C-Programing/src/Kadai$ gcc -Wall 28kadai18.2.c
f11@DESKTOP-F11:/mnt/c/Git/C-Programing/src/Kadai$ ./a.out
(52.1/(-2*3.14))+8
( 52.10 / ( - 2.00 * 3.14 ) ) + 8.00 
END
f11@DESKTOP-F11:/mnt/c/Git/C-Programing/src/Kadai$ 
*/