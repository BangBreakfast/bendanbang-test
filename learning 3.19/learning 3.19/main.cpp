#include <iostream>
#include <cstring>
using namespace std;

class Array2 {
private:
    int **n;
public:
    Array2 (int n_,int m_)
    {
        n=new int*[n_];
        for(int i=0;i<n_;i++)
        {
            n[i]=new int[m_];
        }
    }
    Array2 (){}
    int* operator [](int a)
    {
        return n[a];
    }
    int operator ()(int x, int y)
    {
        return n[x][y];
    }
    // 在此处补充你的代码
};

int main() {
    Array2 a(3,4);
    int i,j;
    for(  i = 0;i < 3; ++i )
        for(  j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;     b = a;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}
