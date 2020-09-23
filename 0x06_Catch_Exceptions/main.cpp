#include <iostream>

using namespace std;

struct DividedByZeroException : public exception{
    //  一定要重载 what 方法
    const char * what () const throw ()
    {
        return "Division by zero condition!";
    }
};

// double division(int a, int b) noexcept       // 不会抛出任何错误 / won't throw any exception
// double division(int a, int b) throw()        // 遇上一行一样 / same as above
// double division(int a, int b) throw(DividedByZeroException)      // 只会抛出 DividedByZeroException
double division(int a, int b)
{
    if( b == 0 )
    {
        throw DividedByZeroException();
    }
    return (a/b);
}

// 通过继承来自定义错误

int main() {

    try {
        division(1, 0);
    } catch (DividedByZeroException e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
