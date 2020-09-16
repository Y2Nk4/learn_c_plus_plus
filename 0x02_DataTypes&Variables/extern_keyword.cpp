//
// Created by Y2Nk4 on 2020/9/16.
//

#include <iostream>
using namespace std;

extern int func();  // 尝试注释掉这一行编译

int main (){
    int val = func();
    cout << "val:\t" << val;

    return 0;
}

int func(){
    return 1;
}