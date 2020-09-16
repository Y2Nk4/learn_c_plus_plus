## 0x02 DataTypes & Variables | 数据类型 & 变量

### 1. 基本的内置类型

| Type      | 关键字 |
| ----      | ----  |
| 布尔值     | bool     |
| 字符型     | char     |
| 整型       | int      |
| 浮点型     | float    |
| 双浮点型    | double   |
| 无类型    | void      |
| 宽字符型    | wchar_t  |

其中 `wchar_t` 由下面语句得来：
```c++
typedef short int wchar_t;
```
所以可以知道 `wchar_t` 实际上的空间和 `short int` 一样，为 2 个字节。

| Type      | 位 (字节数) | 范围 |
| ----      |   ----    | ---- |
| char      |   1       | 	-128 到 127 或者 0 到 255 |
| unsigned char |   1       | 	0 到 255 |
| signed char   |   1       | 	-128 到 127 |
| int       | 4         | -2147483648 到 2147483647 |
| unsigned int  | 4     | 0 到 4294967295|
| signed int    | 4         | -2147483648 到 2147483647 |
| short int     | 2         | -32768 到 32767 |
| unsigned short int    | 2         | 0 到 65,535 |
| signed short int     | 2         | -32768 到 32767 |
| long int      | 8         | -9,223,372,036,854,775,808 到 9,223,372,036,854,775,807 |
| unsigned long int      | 8         | 0 到 18,446,744,073,709,551,615 |
| signed long int       | 8 |   -9,223,372,036,854,775,808 到 9,223,372,036,854,775,807 |
| float     | 4         | 4 | 精度型占4个字节（32位）内存空间，+/- 3.4e +/- 38 (~7 个数字) |
| double    | 8         | 双精度型占8 个字节（64位）内存空间，+/- 1.7e +/- 308 (~15 个数字) |
| long double   | 16    | 长双精度型 16 个字节（128位）内存空间，可提供18-19位有效数字。 |
| wchar_t   | 2 或 4 个字节 | 	1 个宽字符 |

### 2. typedef 声明
如上面提及的 wchar_t 类型，我们也可以自行使用 `typedef` 来定义我们自己的类型。

```c++
typedef type newname; 
```

### 3. Enum 枚举类型 
枚举类型(enumeration)是C++中的一种派生数据类型，它是由用户定义的若干枚举常量的集合。

如果一个变量只有几种可能的值，可以定义为枚举(enumeration)类型。所谓"枚举"是指将变量的值一一列举出来，变量的值只能在列举出来的值的范围内。

创建枚举，需要使用关键字 enum。枚举类型的一般形式为：

```c++
enum 枚举名{ 
     标识符[=整型常数], 
     标识符[=整型常数], 
... 
    标识符[=整型常数]
} 枚举变量;
```
如果枚举没有初始化, 即省掉"=整型常数"时, 则从第一个标识符开始。

例如，下面的代码定义了一个颜色枚举，变量 c 的类型为 color。最后，c 被赋值为 "blue"。

### 4. 变量声明

变量声明向编译器保证变量以给定的类型和名称存在，这样编译器在不需要知道变量完整细节的情况下也能继续进一步的编译。
变量声明只在编译时有它的意义，在程序连接时编译器需要实际的变量声明。

当您使用多个文件且只在其中一个文件中定义变量时（定义变量的文件在程序连接时是可用的），变量声明就显得非常有用。您可以使用 extern 关键字在任何地方声明一个变量。
虽然您可以在 C++ 程序中多次声明一个变量，但变量只能在某个文件、函数或代码块中被定义一次。

例如在 [extern_keyword.cpp](./extern_keyword.cpp) 文件中，我们在 main 方法中调用了 `func` 函数，但是 `func` 是在 `main` 方法后面才定义的
若是直接调用，则会报错:
```shell script
g++ extern_keyword.cpp -o ./tmp.exe
extern_keyword.cpp: In function 'int main()':
extern_keyword.cpp:11:15: error: 'func' was not declared in this scope
   11 |     int val = func();
      |               ^~~~

Process finished with exit code 1
```

若在 `main` 函数上方使用 `extern` 关键字声明了 `func` 方法，程序则可以正常编译运行。

在这里，我们使用 `extern` 关键字向编译器保证了这个变量/方法以给定的类型和名称存在，让其继续进一步的编译。

### 5. Variable Scope | 变量作用域 

#### 局部变量
在函数或一个代码块内部声明的变量，称为局部变量。
它们只能被函数内部或者代码块内部的语句使用。

在 [variable_scope.cpp](./variable_scope.cpp) 中，我们在
`foo` 函数中尝试输出 `b` 变量，但因为 `b` 变量只在 `main` 函数代码块的作用域中
声明，所以编译时会报错：
```shell script
g++ variable_scope.cpp -o ./tmp.exe
variable_scope.cpp: In function 'int foo()':
variable_scope.cpp:11:28: error: 'b' was not declared in this scope
   11 |     cout << "b in foo:" << b << endl; //error: 'b' was not declared in this scope
      |                            ^

Process finished with exit code 1
```
#### 全局变量
与局部变量相对的是全局变量，即在所有函数外部定义的变量（通常是在程序的头部）。
全局变量的值在程序的整个生命周期内都是有效的。

全局变量可以被任何函数访问。也就是说，全局变量一旦声明，在整个程序中都是可用的。

### 6. 常量与修饰符类型

我在这里不多作说明，可以看菜鸟教程的几篇文章了解：
- [C++常量](https://www.runoob.com/cplusplus/cpp-constants-literals.html)
- [C++ 修饰符类型](https://www.runoob.com/cplusplus/cpp-modifier-types.html)

### 7. 存储类
存储类定义 C++ 程序中变量/函数的范围（可见性）和生命周期。这些说明符放置在它们所修饰的类型之前。下面列出 C++ 程序中可用的存储类：
- auto
- register
- static
- extern
- mutable
- thread_local (C++11)

注：从 C++ 17 开始，**auto** 关键字**不再是** C++ 存储类说明符，且 `register` 关键字**被弃用**。

#### Static 存储类
static 存储类指示编译器在程序的生命周期内保持局部变量的存在，
**而不需要在每次它进入和离开作用域时进行创建和销毁**。
因此，使用 static 修饰局部变量可以在函数调用之间保持局部变量的值。

static 修饰符也可以应用于全局变量。当 static 修饰全局变量时，会使变量的作用域限制在声明它的文件内。

在 [storage_classes.cpp](./storage_classes.cpp) 中演示了 static 存储类的一个使用场景。
这使得某些需要重复使用的变量（例如计数器），不需要被定义成全局变量。

#### extern 存储类
在前面我们已经介绍过了 `extern`，这里不作重复论述。

#### mutable & thread_local
剩余的 `mutable` 和 `thread_local` 存储类可以在 [C++ 存储类](https://www.runoob.com/cplusplus/cpp-storage-classes.html) 
这篇文章中了解更多。