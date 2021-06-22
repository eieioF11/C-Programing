//Reverse polish notation for singke digit
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
bool op(char b)
{
    return b == '+' || b == '-' || b == '*' || b == '/';
}
bool prio(char a, char b)
{
    // ------- Add -------
    if (a == '(')
    {
        return true;
    }
    // ------- End -------
    if (a == '+' || a == '-')
    {
        return true;
    }
    if (b == '+' || b == '-')
    {
        return false;
    }
    return true;
}
double posfix(const std::string &expression)//逆ポーランド記法の式を入力
{
    double fst, scd, ans;
    //std::cout << expression << std::endl;
    std::stringstream postfString(expression);//空白区切りの抽出
    std::vector<double> temp;
    std::string schar;
    while (postfString >> schar)
    {
        //std::cout << schar << std::endl;
        if (op(schar[0]))//演算子が来たとき
        {
            //スタックから数値を取り出す
            fst = temp.back();
            temp.pop_back();
            scd = temp.back();
            temp.pop_back();
            //std::cout << fst << "," << scd << "=";
            switch (schar[0])//演算子に応じて計算する
            {
            case '+':
                ans = scd + fst;
                break;
            case '-':
                ans = scd - fst;
                break;
            case '*':
                ans = scd * fst;
                break;
            case '/':
                ans = scd / fst;
                break; // check if fat !=0
            }
            //std::cout << ans << std::endl;
            temp.push_back(ans);//計算結果をスタックにpushする
        }
        else//数値が来たとき
        {
            temp.push_back(std::stod(schar));//スタックにpush
        }
    }
    return temp[0]; //last element is the answer
}
int main()
{
    std::string siki;
    std::string rpoli;
    std::stack<char> que;
    double ans;
    int cnt = 0;
    std::cout << "Please input one-digit formula" << "\n";
    std::cin >> siki;//数式の入力
    for (int i = 0; i < siki.size(); i++)
    {
        // ------- Revise ------
        if (siki[i] != '(' && siki[i] != ')' && op(siki[i]) == false)//数値が来たときの処理
        {
            // ------- End------
            cnt++;
            if (cnt == 1)
            {
                rpoli = siki[i];
            }
            else
            {
                rpoli = rpoli + " " + siki[i];
            }
        }
        // --------------------- Add ----------------------------
        //()が来たときの処理
        if (siki[i] == '(')
        {
            que.push(siki[i]);
        }
        if (siki[i] == ')')
        {
            while (que.top() != '(')
            {
                rpoli = rpoli + " " + que.top();
                que.pop();
            }
            que.pop();
        }
        // --------------------- End ----------------------------
        if (op(siki[i]) == true)//演算子が来たときの処理
        {
            if (que.empty() || (que.empty() == false && prio(que.top(), siki[i])))
            {
                que.push(siki[i]);//演算子をスタックにpush
            }
            else
            {
                while (que.empty() == false && prio(que.top(), siki[i]) == false)
                {
                    rpoli = rpoli + " " + que.top();//スタックの一番上にある演算子を追加
                    que.pop();
                }
                que.push(siki[i]);
            }
        }
    }
    while (que.empty() == false)
    {
        rpoli = rpoli + " " + que.top();
        que.pop();
    }
    std::cout << rpoli << std::endl;//逆ポーランド記法に変換した式を表示
    ans = posfix(rpoli);//計算
    std::cout << std::endl << ans << std::endl;//結果表示
    return 0;
}
/*
出力結果
f11@DESKTOP-F11:/mnt/c/Git/C-Programing/src/Kadai$ g++ -Wall SP009.cpp 
SP009.cpp: In function ‘int main()’:
SP009.cpp:81:23: warning: comparison of integer expressions of different signedness: ‘int’ and ‘std::__cxx11::basic_string<char>::size_type’ {aka ‘long unsigned int’} [-Wsign-compare]
   81 |     for (int i = 0; i < siki.size(); i++)
      |                     ~~^~~~~~~~~~~~~
f11@DESKTOP-F11:/mnt/c/Git/C-Programing/src/Kadai$ ./a.out
Please input one-digit formula
(1+4)*(3+7)/5
1 4 + 3 7 + 5 / *

10
f11@DESKTOP-F11:/mnt/c/Git/C-Programing/src/Kadai$ ./a.out
Please input one-digit formula
 (1+4)*(6/3-4)                            
1 4 + 6 3 / 4 - *

-10
f11@DESKTOP-F11:/mnt/c/Git/C-Programing/src/Kadai$ ./a.out
Please input one-digit formula
(1+2)/(3+4)+(5-6)/(7+8)
1 2 + 3 4 + / 5 6 - 7 8 + / +

0.361905
f11@DESKTOP-F11:/mnt/c/Git/C-Programing/src/Kadai$ 
*/