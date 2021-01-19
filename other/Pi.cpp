#include <cstdio>
#include <iostream>
#include <iomanip>
#define N 100000000

using namespace std;

int main(void){
    double cnt = 0.0;
    long count=0;
    cout << "Calculating " << endl;
    for(int i = 0; i < N; i++)
    {
        double x = (double)rand()/RAND_MAX;
        double y = (double)rand()/RAND_MAX;
        if((x*x + y*y) <= 1.0)
            cnt += 1.0;
        cout << "\r" << count << "/" << N << flush;
        count++;
    }
    double PI=cnt / N * 4.0;
    cout << endl << "Finish!" << endl;
    cout << "円周率：" << setprecision(70) << PI << endl;
    return 0;
}