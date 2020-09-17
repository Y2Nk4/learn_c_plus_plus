#include <iostream>
using namespace std;

class people{
    public:
        float age = 0;
        int height = 0;
        int weight = 0;
        // 在类中使用枚举值
        enum { Male, Female } sex;

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

    protected:
        int execProtect() {
            return 1;
        }
};

int main() {
    people John;
    John.age = 19;
    John.sex = people::Male;    // 使用类的枚举值
    cout << "John is " << John.getSex() << ", " << John.age << " year old" << endl;

    // cout << "Call Protected: " << John.execProtect() << endl;

    cout << "Call Protected func through public method: " << John.execProtectedFuncInPublic() << endl;

    return 0;
}
