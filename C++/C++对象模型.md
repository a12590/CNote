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

> 以constructor来配置一个class object的情况类似

#### 2）delete

```
delete pi;
```
delete pi时，如果pi是0，C++要求delete运算符不要有操作。因此”编译器“必须为此调用构造一层保护：

```
if(pi != 0)
    __delete(pi);   //（__delete即下面会说到的operator delete）释放内存，但是pi并不会设为为0
```

> destructor的应用极为相似，在__delete前会调用destructor

#### 3）operator new和operator delete的实现

一般的library对于new运算符的实现操作都很直截了当，但有两个精巧之处值得斟酌（以下版本并未考虑exception handling）：

```
extern void* operator new(size_t size)
{
    if(size == 0)
        size = 1;
    void *last_alloc;
    while(!(last_alloc = malloc(size))){
        if(_new_handler)
            (*_new_handler)();
        else
            return 0;
    }
    return last_alloc;
}
```

这虽然这样是合法的：

```
new T[0];
```

但语言要求每一次对new的调用都必须传回一个独一无二的指针。解决此问题的传统方法是传回一个指针，指向一个默认为1 byte的内存区块（上述代码中将size设为1的原因）

上述实现允许使用者提供一个属于自己的_new_handler()函数

operator delete也总是以标准的C free()完成：

```c++
extern void operator delete(void *ptr)
{
    if(ptr)
        free((char*)ptr);
}
```

#### 4）针对数组的new语意

```
int *p_array = new int[5];
```

vec_new()不会真正地被调用，因为它的主要功能是把default constructor施行于class objects所组成的数组的每一个元素身上，倒是operator new会被调用：

```
int *p_array = (int*)__new(5 * sizeof(int));
```

相同的情况：

```c++
//struct simple_aggr{float f1,f2;};
simple_aggr *p_aggr = new simple_aggr[5];
```

vec_new()也不会被调用。因为simple_aggr并没有定义一个constructor或destructor，所以配置数组以及清除p_aggr数组的操作，只是单纯地获得内存和释放内存而已。由operator new和operator delete来完成绰绰有余

如果class定义了一个default constructor，某些版本的vec_new()就会被调用

当 ```delete``` 一个指向数组的指针时，C++2.0版之前，需要提供数组的大小。而2.1版后，不需要提供数组大小，只有在 ```[]``` 出现时，编译器才寻找数组的维度。否则它便假设只有单独一个object要被删除：

```c++
//正确的代码应该是delete [] p_array;
delete p_array;
```

只有第一个元素会被析构。其它元素仍然存在——虽然相关的内存已经被要求归还了

由于新版可以不提供数组大小，那么如何记录数组的元素，以便在 ```delete [] arr;``` 时使用？

* 一个明显的方法是为vec_new()所传回的每一个内存区块配置一个额外的word，然后把元素个数包藏在这个word之中，通常这种被包藏的数值称为cookie
* Jonathan和Sun编译器决定维护一个”联合数组“，防止指针及大小。Sun也把destructor的地址维护于此数组之中

cookie策略有一个普遍引起忧虑的话题，如果一个坏指针被交给delete_vec()，取出来的cookie自然是不合法的。一个不合法的元素个数和一个坏指针的起始地址，会导致destructor以非预期的次数被实施于一段非预期的区域。然而在”联合数组“的策略下，坏指针的可能结果就只是取出错误的元素个数而已

**避免以一个base class指针指向一个derived class objects所组成的数组**：

```c++
Point *ptr = new Point3d[10];
```

实施于数组上的destructor，是根据交给vec_delete()函数的”被删除的指针类型的destructor“——在本例中就是Point destructor，与我们的期望不符。此外，每一个元素的大小也一并被传递过去（本例中是Point class object的大小）。这就是vec_delete()如何迭代走过每一个数组元素的方式。因此整个过程失败了，不只是因为执行了错误的destructor，而且自从第一个元素之后，该destructor即被施行于不正确的内存区块中

测试程序：

```
class base{
    base() {cout << "base constructor" << endl;}
    virtual ~base() {cout << "base destructor" << endl;}
};

class derived : public base{
public:
    derived() {cout << "derived constructor" << endl;}
    virtual ~derived() {cout << "derived destructor" << endl;}
};

int main()
{
    base *arr = new derived[5];
    delete [] arr;
    return 0;
}
```

输出如下：

```
//new时构造出了5个子类对象，delete时，调用的是基类的析构函数
base constructor
derived constructor
base constructor
derived constructor
base constructor
derived constructor
base constructor
derived constructor
base constructor
derived constructor
base destructor
base destructor
base destructor
base destructor
base destructor
```

## 6.3 临时性对象

分析下列3个语句产生的临时对象：

1. ```T c = a + b;```
2. ```c = a + b;```
3. ```a + b;```

对于 ```T c = a + b;``` C++标准允许编译器厂商有完全的自由度：

* 编译器可以产生一个临时对象，放置a+b的结果，然后再使用T的copy constructor，把该临时性对象当作C的初始值
* 编译器也可以直接以拷贝构造的方式，将a+b的值放到C中（2.3节），于是不需要临时对象，以及对其的constructor和destructor
* 视operator+()的定义而定，NRV(named return value)优化也可能实施，这将导致直接在c对象中求表达式结果，避免执行copy constructor和具名对象的destructor

