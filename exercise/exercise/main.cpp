//
//  main.cpp
//  exercise
//
//  Created by 高立人 on 2018/3/2.
//  Copyright © 2018年 高立人. All rights reserved.
//

#include <iostream>
using namespace std;

class A{
private:
    int value;
public:
    A(int v_):value(v_){};
    A &operator = (A &a) {value=a.value+1;return *this;}
    int operator + (A &a) {return value+a.value-1;}
    ostream &operator<< (ostream &cout,const A &n){cout<<n.value;return cout;}
    int &getValue(){return value;}
};

int main() {
    A a(3);
    A b=a;
    cout<<b<<endl;
    cout<<a+b-2<<endl;
    cout<<a.getValue<<endl;
    a.getValue=10;
    cout<<a<<endl;
    return 0;
}

