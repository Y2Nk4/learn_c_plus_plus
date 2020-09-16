//
// Created by Y2Nk4 on 2020/9/16.
//

#include <iostream>

using namespace std;

int main () {
    /* typedef 定义自定义类型 */
    typedef int meter;
    meter distance = 100;
    cout << "distance: \t" << distance << endl;

    /* 枚举 */
    enum color{ blue, red, yellow=5, green } c;
    color b; // 复用枚举类型
    color d;
    b = blue;
    c = green;

    cout << "b: \t" << b << endl;
    cout << "c: \t" << c << endl;
    cout << "d: \t" << d << endl;

    return 1;
}