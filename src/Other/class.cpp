#include <iostream>
#include <stdio.h>
using namespace std;

class name
{
	private:
		int name2;
		double name1;
	public:
		int casti(double name)
		{
			name2=(double)name;
			//printf("%d\n",name2);
			return name2;
		}
		double castd(double name)
		{
			name1=(int)name;
			//printf("%f\n",name1);
			return name1;
		}
};
int main()
{
	double i=0.00;
	name obj;
	name*p=&obj;
	//using namespeace std を書かない場合 =>出力 std::cout << "出力する文字" << std::endl; /入力 std::cin >> 変数名;
	cout << "double型の値を入力してください" << endl; 
	cin >> i ;//入力 
	int num=p->casti(i);
	cout << "int変換した値は" << num << "です" << endl/*改行*/;//出力
	return 0;
}
