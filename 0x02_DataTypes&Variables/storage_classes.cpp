//
// Created by Y2Nk4 on 2020/9/16.
//
#include <iostream>
using namespace std;

int addSelf (){
    static int i = 0;
    return i++;
}

int main(){
    // register
    register int a = 1;
    cout << "a:" << a << endl;
    // C++编译器发现程序中需要取register变量的地址时，register对变量的声明变得无效。
    cout << "a addr:" << &a << endl;

    cout << "addSelf: " << addSelf() << endl;   // 0
    cout << "addSelf: " << addSelf() << endl;   // 1
    cout << "addSelf: " << addSelf() << endl;   // 2
    cout << "addSelf: " << addSelf() << endl;   // 3

    return 1;
}