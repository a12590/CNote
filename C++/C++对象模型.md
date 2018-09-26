<!-- GFM-TOC -->
* [第2章 构造函数语意学](#第2章-构造函数语意学)
    * [2.1 默认构造函数的构造操作](#21-默认构造函数的构造操作)
    * [2.2 拷贝构造函数的构造操作](#22-拷贝构造函数的构造操作)
    * [2.3 程序转换语意学](#23-程序转换语意学)
    * [2.4 成员初始化列表](#24-成员初始化列表)
* [第3章 Data语意学](#第3章-data语意学)
    * [3.1 Data Member的绑定](#31-data-member的绑定)
    * [3.2 Data Member的布局](#32-data-member的布局)
    * [3.3 Data Member的存取](#33-data-member的存取)
    * [3.4 继承与Data Member](#34-继承与data-member)
    * [3.5 指向Data Members的指针](#35-指向data-members的指针)
* [第4章 Function语意学](#第4章-function语意学)
    * [4.1 Member的各种调用方式](#41-member的各种调用方式)
    * [4.2 Virtual Member Functions虚函数](#42-virtual-member-functions虚函数)
    * [4.3 指向Member Function的指针](#43-指向member-function的指针)
* [第5章 构造、析构、拷贝语意学](#第5章-构造析构拷贝语意学)
    * [5.1 无继承情况下的对象构造](#51-无继承情况下的对象构造)
    * [5.2 继承体系下的对象构造](#52-继承体系下的对象构造)
    * [5.3 对象拷贝语意学](#53-对象拷贝语意学)
    * [5.4 析构语意学](#54-析构语意学)
* [第6章 执行期语意学](#第6章-执行期语意学)
    * [6.1 静态对象的构造和析构](#61-静态对象的构造和析构)
    * [6.2 new和delete运算符](#62-new和delete运算符)
    * [6.3 临时性对象](#63-临时性对象)
* [附：使用gdb分析对象模型](#附使用gdb分析对象模型)
<!-- GFM-TOC -->

# 第2章 构造函数语意学

## 2.1 默认构造函数的构造操作

考虑如下代码；

```
class Foo{
public:
    int val;
    Foo *pnext;
};

void foo_bar()
{
    Foo bar;
    if(bar.val || bar.pnext)
}
```
上述代码是否会合成默认的拷贝构造函数？首先2个需要：
* **编译**
* **程序**：上述的代码是这个

那么再来考虑是否会：

* 在*C++ ARM**中：只有编译器才会合成，所以上面的不会
* **C++ Standard**：如果没有任何用户声明的构造函数，那么会有一个more构造函数被隐式声明，但是这样被隐式舍命。。

## 2.2 拷贝构造函数的构造操作
* **默认逐成员初始化**
* **逐成员初始化(Memberwise Initialization)**：
* **位逐次拷贝(Bitwise Copy Semantics)**
```
class Word{
public:
    Word(const char*);
    ~Word(){delete [] str;}
private:
    int cnt;
    char *str;
}
```
如果类X没有显示的拷贝构造函数，那么在用一个类X的对象a初始化


## 6.2 new和delete运算符

#### 1）new

```
int *pi = new int(5);
```

实际上是由两个步骤完成的：

1. 通过适当的new运算符函数实例，配置所需内存：```int *pi = __new(sizeof(int));```
2. 将配置得来的对象设置初值：```*pi = 5;```

更进一步，初始化操作应该在内存配置成功后才执行：

```
int *pi;
if(pi = __new(sizeof(int))) //（__new即下面会说到的operator new）
    *pi = 5;
```


