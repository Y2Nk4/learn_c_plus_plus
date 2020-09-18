## 0x05 Class & Object | 类与对象

### 1. 声明类

```c++
class classname{
    public:
        // 公有成员
        int num1 = 0;   // 声明一个公有属性
        
        int func (){    // 声明一个公有方法
            return 1;
        }

    protected:
        // 受保护的成员
    private:
        // 私有成员
};

classname object;       // 通过 `classname` 类构建名为 `object` 的对象
```

### 2. 类访问修饰符
数据封装是面向对象编程的一个重要特点，它防止函数直接访问类类型的内部成员。
类成员的访问限制是通过在类主体内部对各个区域标记 public、private、protected 来指定的。
关键字 public、private、protected 称为访问修饰符。

一个类可以有多个 public、protected 或 private 标记区域。
每个标记区域在下一个标记区域开始之前或者在遇到类主体结束右括号之前都是有效的。
**成员和类的默认访问修饰符是 private。**


在 [main.cpp](./main.cpp) 中，若取消 `第36行` 的注释：
```c++
Line 36: cout << "Call Protected: " << John.execProtect() << endl;
```
则会报错：
```shell script
g++ main.cpp -o ./tmp.exe
main.cpp: In function 'int main()':
main.cpp:36:52: error: 'int people::execProtect()' is protected within this context
   36 |     cout << "Call Protected: " << John.execProtect() << endl;
      |                                                    ^
main.cpp:25:13: note: declared protected here
   25 |         int execProtect() {
      |             ^~~~~~~~~~~

Process finished with exit code 1
```
这是因为我们不允许在类的外部访问 `受保护成员(protected)` 和 `私有成员(private)`。

若想在外部访问 `受保护成员` 或 `私有成员`，我们可以通过在 `公共成员` 中添加一个方法来访问这些属性或方法。

如 [main.cpp](./main.cpp) 中，我们在公共成员中添加了 `execProtectedFuncInPublic`
来间接调用了受保护的方法 `execProtect`

```c++
    ...
    public:
        int execProtectedFuncInPublic() {
            return this->execProtect();
        }

    protected:
        int execProtect() {
            return 1;
        }
    ...
```

然后尝试在 `main` 函数中调用 `execProtectedFuncInPublic` 方法，我们就能获取到 `execProtect` 方法放回的值：

```c++
Line 42: cout << "Call Protected func through public method: " << John.execProtectedFuncInPublic() << endl;

// $ Call Protected func through public method: 1
```

**值得注意的是：**
私有成员变量或函数在类的外部是不可访问的，甚至是不可查看的。只有类和友元函数可以访问私有成员。

而保护成员在派生类（即子类）中是可访问的。

### 3. 类访问修饰符在继承中的特点

在继承时，我们可以选择 `public`, `protected`, `private` 三种继承方式中的一种
来继承，来更改基类各成员属性和方法的访问属性。

**如果继承时不显示声明是 private，protected，public 继承，则默认是 private 继承，在 struct 中默认 public 继承**

```c++
class A{
    public:
        int a = 10;
};
class B : public A{
    public:
        int b = 10;
}
```

|继承方式|	基类的public成员|	基类的protected成员|	基类的private成员|	继承引起的访问控制关系变化概括|
|----|----|----|----|----|
|public继承|	仍为public成员|	仍为protected成员|	不可见|	基类的非私有成员在子类的访问属性不变|
|protected继承|	变为protected成员|	变为protected成员|	不可见|	基类的非私有成员都为子类的保护成员|
|private继承|	变为private成员|	变为private成员|	不可见|	基类中的非私有成员都称为子类的私有成员|


### 4. 在类中使用枚举值
在 [main.cpp](./main.cpp) 中，我们定义了一个 `people` 类，
并在公有成员中定义了枚举类型 `sex`。

若需要在外部修改 `sex` 的值，我们可以通过 `Object.sex = people::Male` 来更新。

```c++
Line 33:    John.sex = people::Male;    // 使用类的枚举值
Line 34:    cout << "John is " << John.getSex() << ", " << John.age << " year old" << endl;
```

### 5. 构造函数
类的**构造函数**是类的一种特殊的成员函数，它会在每次创建类的新对象时执行。

**构造函数的名称与类的名称是完全相同的**，并且**不会**返回任何类型，也不会返回 void。
构造函数可用于为某些成员变量设置初始值。