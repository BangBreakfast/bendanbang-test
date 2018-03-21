#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;
using namespace std;
class Point {
private:
    int x, y;
public:
    Point(int x_,int y_)
    {
        x=x_;
        y=y_;
    }
    Point operator ++ (int _tmp) {
        Point preValue(*this);
        ++x; ++y;
        return preValue;
    }
    friend ostream &operator  << (ostream &cout,const Point &p)
    {
        cout<<p.x<<','<<p.y;
        return cout;
    }
};
int main() {
    Point p(2, 4);
    cout << p;    // 输出 2, 4
    cout << p++;  // 输出 2, 4
    cout << p;    // 输出 3, 5
    return 0;
}

