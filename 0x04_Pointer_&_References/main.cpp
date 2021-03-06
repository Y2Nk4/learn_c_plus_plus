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
    int& d = a;     // 创建引用变量
    int e = 12;
    int g;

    int *b = &a;
    // int c = &a;  // 语法错误
    cout << "b:" << b << " | *b:"<< *b << " | addr(&b): " << &b << endl;
    cout << "b 在 " << &b << " 这块内存空间内存储了值 " << b << " ，这是一个内存地址，这个对应的内存地址存储了：" << *b << endl << endl;

    cout << "int* 的大小 " << sizeof(int*) << endl;
    cout << "float* 的大小 " << sizeof(float*) << endl;
    cout << "char* 的大小 " << sizeof(char*) << endl << endl;

    cout << "a:" << a << " | addr: " << &a << endl;
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