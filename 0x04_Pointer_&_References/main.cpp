#include <iostream>
using namespace std;

void swap(int& x, int& y);

int main() {
    cout << "Hello, World!" << endl;

    char text1[] = "Hello";
    char text2[] = "Hello";
    // char *text3 = &text1;

    cout << "Is same? " << (text1 == text2) << endl;
    cout << "text1: " << text1 << &text1 << endl;
    cout << "text2: " << text2 << &text2 << endl;
    // cout << "text3: " << text3 << &text3 << endl;

    int a = 12;
    int *b = &a;
    int *c = &a;
    int& d = a;
    int e = 12;
    int g;

    cout << "b:" << *b << endl;
    cout << "c:" << (*c == a) << endl;
    cout << "c: " << c << " addr: " << &c << endl;
    cout << "a:" << a << " addr: " << &a << endl;
    cout << "b:" << b << " is same: " << " addr: " << &b << endl;
    cout << "d:" << d << " is same: " << (a == d) << " addr: " << &d << endl;
    cout << "e:" << e << " is same: " << (a == e) << " addr: " << &e << endl;

    // Reference
    int f = 13;
    cout << "a:" << a << " addr: " << &a << endl;
    cout << "f:" << f << " addr: " << &f << endl;

    swap(a, f);

    cout << "a:" << a << " addr: " << &a << endl;
    cout << "f:" << f << " addr: " << &f << endl;

    // 通过引用转换后，内存地址(指针)还是原来的

    return 0;
}

// Reference for parameter
void swap(int& x, int& y){
    int tmp = x;
    x = y;
    y = tmp;
}