#include <stdio.h>
/*******************************************
 クラス　　T3
 出席番号　　35
 名前  西澤　英志
********************************************/
int main(void)
{
    int n;
    printf("sizeof 1 %u  sizeof(unsibned)-1 %u  sizeof n+2 %u\n",(unsigned)sizeof 1,(unsigned)sizeof(unsigned)-1,(unsigned)sizeof n+2);
    printf("sizeof+1 %u  sizeof(double)-1 %u  sizeof(n+2) %u\n",(unsigned)sizeof+1,(unsigned)sizeof(double)-1,(unsigned)sizeof(n+2));
    printf("sizeof-1 %u  sizeof((double)-1) %u  sizeof(n+2.0) %u\n",(unsigned)sizeof-1,(unsigned)sizeof((double)-1),(unsigned)sizeof(n+2.0));
    /*
    ＜考察＞
    sizeof 1
        int型の値なのでint型のサイズ4が表示される
    sizeof (unsigned)-1
        unsignedの型のサイズ(4byte)から１引いたあたいになるため3が表示される
    sizeof n+2
        変数nはint型でint型のサイズ(4byte)に2を足したため6が表示される
    sizeof +1
        int型の値なのでint型のサイズ4が表示される
    sizeof(double)-1
        double型のサイズ(8byte)から1引いたため7が表示される
    sizeof(n+2)
        int型の変数nの値に2を足しただけなのでint型のサイズである4が表示される
    sizeof-1
        int型の値なのでint型のサイズ4が表示される
    sizeof((double)-1)
        double型にキャストしてあるのでdouble型のサイズ8が表示される
    sizeof(n+2.0)
        int型の変数nの値に少数型の値2.0を足しているのでdouble型のサイズ8が表示される
    */
    return 0;
}