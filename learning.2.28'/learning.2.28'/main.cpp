#include <iostream>
using namespace std;
class Point {
private:
    int x;
    int y;
public:
    Point() { };
    friend istream &operator >>(istream &s, Point &p)
    {
        s >> p.x >> p.y;
        return s;
    }
    friend ostream &operator <<(ostream &s, const Point &p)
    {
        s << p.x <<","<< p.y ;
        return s;
    }
};
int main()
{
    Point p;
    while(cin >> p) {
        cout << p << endl;
    }
    return 0;
}
