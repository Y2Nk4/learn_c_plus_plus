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

        // 构造函数
        people(string name){
            this->name = name;
            cout << "construct func 'people' is called" << endl;
            cout << "this pointer: " << this << endl;
        }

        // 拷贝构造函数
       /* people(const people &obj){
            this->name = obj.name + "(cloned)";
            cout << "cloned a people: " << obj.name << endl;
        }*/

        // 析构函数
        ~people(){
            cout << this->name << " is gonna be destroyed" << endl;
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

        // 运算符重载
        people operator+(const people& people1){
            cout << "Operator executed inside object " << this->name << endl;

            if (people1.sex == this->sex) {
                cout << "同性不能生孩子~" << endl;

                people empty("Nothing");
                return empty;
            }else{
                people child("Child of " + people1.name + " and " + this->name);
                child.sex = (0 + (rand() % (1 - 0 + 1)) == 1) ? Male : Female;

                cout << endl << "Child " << child.name << " 的指针: " << &child << endl;

                return child;
            }
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

    people Alex("Alex");
    Alex.sex = people::Male;

    people Jennifer("Jennifer");
    Jennifer.sex = people::Female;

    cout << "Try to add John and Alex" << endl;
    people child = John + Alex;
    cout << "Name of the child:" << child.name << endl << endl;

    cout << "Try to add John and Jennifer" << endl;
    people child2 = John + Jennifer;    // 若定义了拷贝构造函数，会调用拷贝构造函数
                                        // 这里是在运算时生成了一个 people 对象，然后赋值运算的时候再生成了一个(赋值运算会调用拷贝构造函数)
                                        // 所以会看到运算时生成的 people 对象的析构函数会被调用
                                        // 输出对象的指针会发现前后对象的指针是不一样的，印证了上面一条。
    cout << "Name of the child:" << child2.name << endl;
    cout << endl << "Child " << child2.name << " 的指针: " << &child << endl;

    return 0;
}
