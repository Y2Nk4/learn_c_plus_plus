#include <iostream>
#include <string>
using namespace std;

class people{
    public:
        float age = 0;
        int height = 0;
        int weight = 0;
        string name;
        // 在类中使用枚举值
        enum { Male, Female } sex;


        people(string name){
            this->name = name;
            cout << "construct func 'people' is called" << endl;
            cout << "this pointer: " << this << endl;
        }

        people(const people &obj){
            cout << "cloned a people: " << obj.name << endl;
        }

        string getSex() {
            if(sex == Male){
                // 若定义为局部变量的话，是无法再代码块外部使用
                // 所以需要使用静态局部变量
                static char text[] = "Male";
                return "Male";
            } else {
                static char text[] = "Female";
                return "Female";
            }
        }

        int execProtectedFuncInPublic() {
            return this->execProtect();
        }

        // 先声明，再在外部定义成员方法
        int func1(int x);

        // 重载
        void saySomething (string word) {
            cout << this->name << " says: " << word << endl;
        }
        void saySomething (int word) {
            cout << this->name << " says: " << word << endl;
        }

    protected:
        int execProtect() {
            return 1;
        }
};

int people::func1(int x) {
    return x * 2;
}

/*class boy: public people{
    public:
        boy(string name):people(name){
            this->sex = Male;
        }
};*/

int main() {
    people John("John");
    John.age = 19;
    John.sex = people::Male;    // 使用类的枚举值
    cout << "John is " << John.getSex() << ", " << John.age << " year old" << endl;

    // cout << "Call Protected: " << John.execProtect() << endl;

    cout << "Call Protected func through public method: " << John.execProtectedFuncInPublic() << endl;
    cout << "Test func: " << John.func1(2) << endl;

    people ClonedJohn = John;   // 创建CloneJohn对象，但是不执行普通的构造函数，而是执行拷贝构造函数
    cout << "John's Pointer: " << &John << " | ClonedJohn's Pointer: " << &ClonedJohn << endl;
    /*boy Kim;
    cout << "Kim's sex is: " << Kim.getSex() << endl;*/

    // 重载测试
    John.saySomething("Hi!");
    John.saySomething(23);

    return 0;
}
