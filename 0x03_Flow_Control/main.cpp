#include <iostream>
using namespace std;

int main() {
    int a = 10;

    if (a > 5) {
        cout << "a is larger than 5!" << endl;
    }

    while (a <= 12){    // continue to run if true
        cout << "a is: " << a << endl;
        a++;
    }

    // for 也是先执行在判断
    for (int i = 0; i < 0; i ++) {     // 声明一个参数的初始值; 条件，如果为true则继续循环; 循环后的操作
        cout << "i is: " << i << endl;

        break;  // 跳出循环
    }

    int b = 0;
    do {
        b++;
        cout << "b is: " << b << endl;
    } while (b <= 10);  //先执行循环，再判断


    // goto 语句
    loop1: for (int x = 0; x <= 10; x++) {
        loop2: for (int y = 0; y <= 10; y++) {
            cout << "x:" << x << " | y:" << y << endl;
            if (y > 3) {
                break;
                // goto loop1; // goto 会使循环重新开始
            }
        }
    }

    return 0;
}
