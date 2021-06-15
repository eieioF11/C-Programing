#include <iostream>
#include "list"
#include "stack"
#include "deque"
#include "algorithm"
#include "iterator"
#include "string"

/*
cout << "AAA" ; -> ターミナルにAAAと表示(改行なし)
endl -> 改行　Ex cout << "AAA" << endl;

*/

int main()
{
    using  namespace std;//using disctive  stdの名前空間を使用する(std省略して関数を使用)　あまりよろしくない

    //文字列のスタックを作る
    cout << endl;
    cout << "***stack***"<<endl;
    stack<string> s;
    //一連の文字列をプッシュオンする
    cout <<  "---push---" << endl;
    for(int i=1;i<10;i++)
    {
        s.push(string(i + 1,(char)(i+64)));//stack の先頭に要素を追加
        cout << s.top() << endl;//stack の先頭にある要素への参照を表示
    }
    //次にポップ オフする
    cout << "---pop---" << endl;
    for(int i=1;i<10;i++)
    {
        cout << s.top() <<endl;//stack の先頭にある要素への参照を表示
        s.pop();//stack の先頭から要素を削除
    }

    cout << endl;

    //文字列のキューを作る
    cout << endl;
    cout << "****deque***" << endl;
    deque<string> dq;

    //一連の文字列をプッシュオンする
    cout <<  "---push---" << endl;
    for(int  i=1;i<10;i++)
    {
        dq.push_back(string(i+1,(char)(i+64)));//deque の末尾に要素を追加
        cout << dq.back() << endl;//末尾要素への参照を表示
    }

    //次にポップオフする
    cout <<  "---pop---" << endl;
    for(int i=1;i<10;i++)
    {
        cout << dq.front() << endl;//先頭要素への参照を表示
        dq.pop_front();//deque の先頭の要素を消去します
    }

    cout << endl;
    return 0;
}
/*
実行結果
***stack***
---push---
AA
BBB
CCCC
DDDDD
EEEEEE
FFFFFFF
GGGGGGGG
HHHHHHHHH
IIIIIIIIII
---pop---
IIIIIIIIII
HHHHHHHHH
GGGGGGGG
FFFFFFF
EEEEEE
DDDDD
CCCC
BBB
AA


****deque***
---push---
AA
BBB
CCCC
DDDDD
EEEEEE
FFFFFFF
GGGGGGGG
HHHHHHHHH
IIIIIIIIII
---pop---
AA
BBB
CCCC
DDDDD
EEEEEE
FFFFFFF
GGGGGGGG
HHHHHHHHH
IIIIIIIIII
*/