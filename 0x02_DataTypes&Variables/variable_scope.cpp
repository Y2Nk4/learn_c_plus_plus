//
// Created by Y2Nk4 on 2020/9/16.
//

#include <iostream>
using namespace std;

int foo(){
    int a = 0;
    cout << "a in foo:" << a << endl;
    // cout << "b in foo:" << b << endl; //error: 'b' was not declared in this scope
    return 0;
}

int main(){
    int a = 10, b = 23;
    cout << "a in main:" << a << endl;
    cout << "a's addr in main:" << &a << endl;
    cout << "b in main:" << b << endl;
    // 局部变量
}