* [一.让自己习惯C++](#一让自己习惯c)
    - [条款02：尽量以const,enum,inline替换\#define](#条款02尽量以constenuminline替换define)
    - [条款03：尽可能使用const](#条款03尽可能使用const)
* [二.构造/析构/赋值运算](#二构造析构赋值运算)
    - [条款04：确定对象被使用前已先被初始化](#条款04确定对象被使用前已先被初始化)
    - [条款05：了解C++默默编写并调用哪些函数](#条款05了解c默默编写并调用哪些函数)
    - [条款06：若不想使用编译器自动生成的函数，就该明确拒绝](#条款06若不想使用编译器自动生成的函数就该明确拒绝)
    - [条款07：为多态基类声明virtual析构函数](#条款07为多态基类声明virtual析构函数)
    - [条款08：别让异常逃离析构函数](#条款08别让异常逃离析构函数)
    - [条款09：绝不在构造和析构过程中调用virtual函数](#条款09绝不在构造和析构过程中调用virtual函数)
    - [条款10：令operator=返回一个reference to \*this](#条款10令operator返回一个reference-to-this)
    - [条款11：在operater=中处理“自我赋值”](#条款11在operater中处理自我赋值)
    - [条款12：复制对象时勿忘其每一个成分](#条款12复制对象时勿忘其每一个成分)
* [三.资源管理](#三资源管理)
    - [条款13：以对象管理资源](#条款13以对象管理资源)
    - [条款14：在资源管理类中小心copying行为](#条款14在资源管理类中小心copying行为)
    - [条款15：在资源管理类中提供对原始资源的访问](#条款15在资源管理类中提供对原始资源的访问)
    - [条款16：成对使用new和delete时要采取相同形式](#条款16成对使用new和delete时要采取相同形式)
    - [条款17：以独立语句将newed对象置入智能指针](#条款17以独立语句将newed对象置入智能指针)
* [四.设计与声明](#四设计与声明)
    - [条款18：让接口容易被正确使用，不易被误用](#条款18让接口容易被正确使用不易被误用)
    - [条款19：设计class犹如设计type](#条款19设计class犹如设计type)
    - [条款20：宁以pass-by-reference-to-const替换pass-by-value](#条款20宁以pass-by-reference-to-const替换pass-by-value)
    - [条款21：必须返回对象时，别妄想返回其reference](#条款21必须返回对象时别妄想返回其reference)
    - [条款22：将成员变量声明为private](#条款22将成员变量声明为private)
    - [条款23：宁以non-member、non-friend替换member函数](#条款23宁以non-membernon-friend替换member函数)
    - [条款24：若所有参数皆需类型转换，请为此采用non-member函数](#条款24若所有参数皆需类型转换请为此采用non-member函数)
    - [条款25：考虑写出一个不抛出异常的swap函数](#条款25考虑写出一个不抛出异常的swap函数)
* [五.实现](#五实现)
    - [条款26：尽可能延后变量定义式的出现时间](#条款26尽可能延后变量定义式的出现时间)
    - [条款27：尽量少做转型动作](#条款27尽量少做转型动作)
    - [条款28：避免返回handles指向对象内部成分](#条款28避免返回handles指向对象内部成分)
    - [条款29：为“异常安全”而努力是值得的](#条款29为异常安全而努力是值得的)
    - [条款30：透彻了解inlining的里里外外](#条款30透彻了解inlining的里里外外)
    - [条款31：将文件间的编译依存关系将至最低](#条款31将文件间的编译依存关系将至最低)
* [六.继承与面向对象设计](#六继承与面向对象设计)
    - [条款32：确定你的public继承塑模出is-a关系](#条款32确定你的public继承塑模出is-a关系)
    - [条款33：避免遮掩继承而来的名称](#条款33避免遮掩继承而来的名称)
    - [条款34：区分接口继承和实现继承](#条款34区分接口继承和实现继承)
    - [条款35：考虑virtual函数以外的其他选择](#条款35考虑virtual函数以外的其他选择)
    - [条款36：绝不重新定义继承而来的non-virtual函数](#条款36绝不重新定义继承而来的non-virtual函数)
    - [条款37：绝不重新定义继承而来的缺省参数值](#条款37绝不重新定义继承而来的缺省参数值)
    - [条款38：通过复合塑模出has-a或“根据某物实现出”](#条款38通过复合塑模出has-a或根据某物实现出)
    - [条款39：明智而审慎地使用private继承](#条款39明智而审慎地使用private继承)
    - [条款40：明智而审慎地使用多重继承](#条款40明智而审慎地使用多重继承)
* [七.模板与泛型编程](#七模板与泛型编程)
    - [条款41：了解隐式接口和编译器多态](#条款41了解隐式接口和编译器多态)
    - [条款42：了解typename的双重意义](#条款42了解typename的双重意义)
    - [条款43：学习处理模板化基类内的名称](#条款43学习处理模板化基类内的名称)
    - [条款44：将与参数无关的代码抽离templates](#条款44将与参数无关的代码抽离templates)
    - [条款45：运用成员函数模板接受所有兼容类型](#条款45运用成员函数模板接受所有兼容类型)
    - [条款46：需要类型转换时请为模板定义非成员函数](#条款46需要类型转换时请为模板定义非成员函数)
    - [条款47：请使用traits classes表现类型信息](#条款47请使用traits-classes表现类型信息)
    - [条款48：认识template元编程](#条款48认识template元编程)
* [八.定制new和delete](#八定制new和delete)
    - [条款49：了解new-handler的行为](#条款49了解new-handler的行为)
    - [条款50：了解new和delete的合理替换时机](#条款50了解new和delete的合理替换时机)
    - [条款51：编写new和delete时需固守常规](#条款51编写new和delete时需固守常规)
    - [条款52：写了placement new也要写placement delete](#条款52写了placement-new也要写placement-delete)

<br>

# 一.让自己习惯C++

##条款02：尽量以const,enum,inline替换\#define

**这个条款或许改为“宁可以编译器换预处理器”比较好

### 1）以const替换\#define

```
#define ASPECT_RATIO 1.653
替换为：
const double AspectRatio = 1.653
```

* **调试的需要**：#define的记号会被预处理器移走，记号名称可能没进入记号表中。因此当#define的宏名称获得一个编译错误，会引起困惑，浪费大量时间追踪错。
* **更小的代码量**：对浮点数而言，使用常量可能比使用#define导致较为小的代码量。

但是，以常量替换#define时候要注意：

* **定义常量指针时：由于常量定义式通常被定义在文件内，因此有必要将指针声明为const**。如：
```
const char* const authorName = "da";
```

* **class专属常量**：class专属常量需要声明在class内部，并且被class使用：
```
class GamePlayer{
    static const int NumTurns = 5;// 常量声明式
    int scores[NumTurns];//使用该常量
};
//通常定义在头文件
const int GamePlayer::NumTurns;
```

### 2）以enum替换\#define

编译器可能不支持类内初始值，因此改用enum：

```
class GamePlayer{
    enum {NumTurns = 5};
    int scores[NumTurns];
}
```

**enum**的行为比较像#define而不像const。例如取一个const的地址时合法的，但是取一个enum非法

### 3）以inline替换\#define
以#define实现宏看起来像函数，并且不会导致函数调用带来的开销。

```
#define CALL_WITH_MAX(a,b) f((a) > (b)? (a):(b))

int a = 5,b = 0;
CALL_WITH_MAX(++a,b); //a被累加2次
CALL_WITH_MAX(++a,b + 10);  //a被累加1次
```

使用inline函数可以减轻为参数加上括号以及参数被核心算多次等问题。同时，inline可以实现一个类内private inline函数

## 条款03：尽可能使用const

### 1）const修饰变量

如果变量本身不应该被修改，应该使用const修饰。这样编译器可以进行保护，确保不会被修改
```
char greeting[] = "hello";;
char *p = greeting; // non-const pointer,non-const data
const char *p = greeting; // non-const pointer,const data
char * const p = greeting; // const pointer, non-const data
const char * const p = greeting; // const pointer,const data
```

* 如果关键字const出现在星号左边，表示被指物是常量
* 如果关键字const出现在星号右边，表示指针本身是常量

### 2）const修饰函数

* 修饰参数时候，和修饰一般常量相同
* **修饰返回值，可以降低因客户错误而造成的意外**

```
Rational a,b,c;
if(a*b == c){

```

### 3）const修饰成员函数

const修饰成员函数有2个好处：
1、**可读性**：使得接口容易被理解，可以知道哪个函数可以改动对象，哪个函数不行
2、**const修饰的成员函数可以作用于const对象

但是需要注意：C++对常量性的定义是bitwise constness，即const成员函数不应该修改对象的任何成员变量。因此，如果成员变量是一个指针，那么不修改指针而修改指针所指之物，也符合bitwise constness：

```
class CTextBlock{
public:
    char& operator[](std::size_t position) const
    {
    return pText[position];
    }// 但其实不恰当
private:
    char* pText;
};

const CTextBlock cctb("Hello"); //声明一个常量对象
char *pc = &cctb[0]; // 调用operator[] 取得一个指针
*pc = 'J'; // cctb现在有了Jello这样的内容
```

还有一种logical constness：一个const成员函数可以修改它所处理的对象内的某些bits，但只有在客户端侦测不出的情况下才行：

```
class CTextBlob{
public:
    std::size_t length() const;
private:
    char *pText;
    std::size_t textLength; //最近一次计算文本区块长度
    bool lengthIsValid; // 目前的长度是否有效
};

std::size_t CTextBlock::length() const{
    if(!lengthIsValid){
        textLength = std::strlen(pText); // 错误！在const成员函数内不能复制
        lengthIsValid = true;
    }
    return textLength;
}
```

但是，C++对常量性的定义是bitwise constness的，所以这样操作是非法，用mutable

```
class CTextBlock{
public:
    std::size_t length() const;
private:
    char *pText;
    mutable std::size_t textLength;
    mutable bool lengthIsValid;
}

std::size_t CTextBlock::length() const{
  if (!lengthIsValid) {
    textLength = std::strlen(pText);    //现在可以这样
    lengthIsValid = true;               //也可以这样
  }
  return textLength;
}
```

## 条款04：确定对象被使用前已先被初始化

**读取未初始化对象的后果**：读取未被初始化的值会导致不明确的行为。

按对象的类型划分：
* **对于内置类型的对象**：永远在使用前初始化
* **类类型的对象** ：初始化责任落在构造函数上
    - **效率问题**
        + 类类型成员的初始化动作发生在构造函数本体之前。

# 二.构造/析构/赋值运算

## 条款05：了解C++默默编写并调用哪些函数

一般情况下，编译器会为类合成下列函数：
* **default构造函数**
* **copy构造函数**：

## 条款09：绝不在构造和析构过程中调用virtual函数

如果希望在继承体系中根据类型在构建对象时表现出不同行为，可以会想到在基类的构造函数中调用一个虚函数：

```
class Transaction {                           //所有交易的基类
public:
    Transaction(){
        ...
        logTransaction();
    }
    virtual void logTransaction() const = 0;  //做出一份因类型不同而不同的日志记录
};

class BuyTransaction: public Transaction {        //派生类
public:
    virtual void logTransaction() const;
};

class SellTransaction: public Transaction {      //派生类
public:
    virtual void logTransaction() const;
};

```

但是最终调用的virtual函数都是基类的版本。同时，因为是纯虚函数，除非定义该函数，否则将报链接错误

**在子类构造期间，virtual函数绝不会下降到派生类阶层。取而代之，对象的作为就像隶属基类类型一样。即派生类对象的基类构造期间，对象的类型是基类而不是派生类；
除此之外，若使用运行期类型信息**（如dynamic_cast和typeid），也会把对象视为基类类型（这样对待是合理的：因为子类部分尚未初始化，如果调用的是子类的虚函数，通常会访问子类部分的数据，会引发安全问题）

**同样的道理也适用于析构函数。一旦派生类析构函数开始执行，对象内的派生类成员变量便呈现未定义值，所以C++视它们仿佛不再存在。进入基类析构函数后对象就成为一个基类对象**

如果希望实现最初的功能，即根据类型产生不同日志记录，那么可以在派生类的成员初始化列表中，向基类传递一些类型相关的信息，基类构造函数根据这些信息生成不同的日志记录，此时日志记录的生成函数不再是virtual函数

<br>

## 条款27：尽量少做转型动作

转型分类：

* C风格的转型
    ```c++
    (T)expression   //将expression转型为T
    T(expression)   //将expression转型为T
    ```
* C++提供的新式转型
    ```c++
    const_cast<T>(expression)
    dynamic_cast<T>(expression)
    reinterpret_cast<T>(expression)
    static_cast<T>(expression)
    ```
    - **static_cast**：只要不包含底层const，都可以使用。适合将较大算术类型转换成较小算术类型
    - **const_cast**：只能改变底层const，例如指向const的指针(指向的对象不一定是常量，但是无法通过指针修改)​，如果指向的对象是常量，则这种转换在修改对象时，结果未定义
    - **reinterpret_cast**：通常为算术对象的位模式提供较低层次上的重新解释。如将int\*转换成char\*。很危险！
    - **dynamic_cast**：一种动态类型识别。转换的目标类型，即type，是指针或者左右值引用，主要用于基类指针转换成派生类类型的指针(或引用)，通常需要知道转换源和转换目标的类型。如果​​转换失败，返回0（转换目标类型为指针类型时）或抛出bad_cast异常（转换目标类型为引用类型时）

应该尽可能使用新式转型：

1. 它们很容易在代码中被辨别出来（无论是人工还是使用工具如grep），因而得以简化”找出类型系统在哪个地点被破坏“的过程
2. 各转型动作的目标越窄化，编译器越可能诊断出错误的运用

**尽量少做转型**：

1. **转型不只是告诉编译器把某种类型视为另一种类型这么简单。任何一个转型动作往往令编译器编译出运行期间执行的代码**
    ```c++
    //示例一
    int x,y;
    ...
    double d = static_cast<double>(x)/y;
    //示例二
    class Base {...};
    class Derived : public Base {...};
    Derived d;
    Base *pd = &d;  //隐式地将Derived*转换为Base*
    ```

* 在示例一中：int转型为double几乎肯定会产生一些代码，因为在大部分体系结构中，int的底层表述不同于double的底层表述
* 在示例二中：会有个偏移量在运行期被实施于Derived\*指针身上，用以取得正确的Base\*地址

2. **很容易写出似是而非的代码**
```
    class Window{
    public:
        virtual void onResize() {...}
        ...
    }
    //错误的做法
    class SpecialWindow: public Window{
    public:
        virtual void onResize(){
            static_cast<Window>(*this).onResize();
            ...  //这里进行SpecialWindow专属行为
        }
        ...
    }
    //正确的做法
    class SpecialWindow: public Window{
    public:
        virtual void onResize(){
            Window::onResize();  //调用Window::onResize作用于*this身上
            ...  //这里进行SpecialWindow专属行为
        }
        ...
    }
    ```
3. **继承中的类型转换效率低**
    * C++通过dynamic_cast实现继承中的类型转换，dynamic_cast的大多数实现效率都是相当慢的。因此，应该避免继承中的类型转换。
    一般需要dynamic_cast，通常是因为想在一个认定为derived class对象身上执行derived class操作，但是拥有的是一个”指向base“的指针或引用。这种情况下有2种办法可以避免转型：
        - **使用容器并在其中存储直接指向derived class对象的指针**：这种做法无法在同一个容器内存储指针”指向所有可能的各种派生类“。如果真要处理多种类型，可能需要多个容器，它们都必须具备类型安全性
        - **将derived class中的操作上升到base class内，成为virtual函数，base class提供一份缺省实现**：缺省实现代码可能是个馊主意，条款34中有分析，但是也比使用dynamic_cast来转型要好

## 条款34：区分接口继承和实现继承

> 纯虚函数一般作为接口，基类一般不提供定义，但是基类可以为纯虚函数提供定义。派生类必须声明纯虚函数，如果想要使用纯虚函数，派生类必须提供一份定义，即使基类已经为该纯虚函数提供定义。如果派生类不提供定义，仍然是一个抽象基类。

1. **声明一个pure virtual函数的目的是为了让derived classes只继承函数接口**
2. **声明（非纯）impure virtual函数的目的，是让derived classes继承该函数的接口和缺省实现**
3. **声明non-virtual函数的目的，是为了让derived classes继承函数的接口和一份强制性的实现

### 1）pure virtual函数

如果某个操作不同派生类应该表现出不同行为，并且没有相同的缺省实现，那么应该使用pure virtual函数，此时派生类只继承接口

### 2）impure virtual函数

如果某个操作不同派生类应该表现出不同行为，并且具有相同的缺省实现，那么应该使用impure virtual函数，此时派生类继承接口和缺省实现

**但是，允许impure virtual函数同时指定函数声明和缺省行为，却可能造成危险：假设引入了一个新的派生类，但是缺省行为并不适用于新的派生类，而新的派生类忘记重新定义新的行为，那么调用该操作将表现出缺省行为，这是不合理的**

```
class Airplane{
public:
    virtual void fly(){}
};
class ModelA:public Airplane{}
class ModelB:public Airplane{}
class ModelC:public Airplane{}
Airplane *p = new ModelC;
p->fly();
```

a) 要避免这种错误，可以将fly改为pure virtual函数，并且将缺省的飞行行为实现为一个protected函数：

```
class Airplane{
public:
    virtual void fly() = 0;
//这是合理的，因为它是Airplane及其derived classes的实现细目。乘客应该只在意飞机能不能飞，不在意它怎么飞
protected:
    //non-virtual函数，因为没有任何一个派生类应该重新定义缺省行为
    void defaultFly(){...}
}
class ModelA: public Airplane{
public:
    virtual void fly(){defaultFly();}
}
class ModelB: public Airplane{
public:
    virtual void fly(){defaultFly();}
}
```

此时，fly变成了pure virtual函数，首先，飞机C必须声明fly函数，如果需要使用，必须为其定义。那么就可以防止因为忘记定义而引起的错误

b) 有人反对以不同函数分别提供接口和缺省实现，像上面的fly和defaultFly。因为他们关心因过渡雷同函数名称而引起的class命名空间污染问题。那么可以将缺省的行为定义在fly中，即为fly实现一份缺省的定义：

```
class Airplane{
public:
    virtual void fly() = 0;
};
void Airplane::fly(){
    // 缺省的fly代码
}

class ModelA: public Airplane{
public:
    virtual void fly(){
        Airplane::fly();
    }
};
```

由于任何派生类想要使用pure virtual函数都必须提供一份定义,那么如果想要使用缺省行为，可以直接在定义中转调用基类的实现。否则，可以定制特殊的行为。因为是纯虚函数，只要不定义就无法使用，因此也可以避免前面的问题

### 3）non-virtual函数

如果某个操作在整个体系中，应该表现出一致的行为，那么应该使用non-virtual函数。此时派生类继承接口和一份强制性实现

<br>

## 条款35：考虑virtual函数以外的其他选择

>

## 条款36：绝不重新定义继承而来的non-virtual函数

从规范上说，[条款34](#条款34区分接口继承和实现继承)提到，如果某个操作在整个继承体系应该是不变的,那么使用non-virtual函数，此时派生类从基类继承接口以及一份强制实现。如果派生类希望表现出不同行为，那么应该使用virtual函数

另一方面，假设真的重新定义了继承而来的non-virtual函数，会表现出下列令人困惑的情况：

```
class B{
public:
    void mf();
};

class D:public B{
public:
    void mf();
}

D x;
B *pB = &x;
D *pD = &x;

pB->mf();
pD->mf();
```

你可能会觉得因为pB和pD指向的是相同的对象，因此调用的non-virtual函数也应该相同，但是事实并非如此。因为**non-virtual函数是静态绑定**，因此实际上调用的函数由指针或引用决定

<br>

## 条款37：绝不重新定义继承而来的缺省参数值

[条款36](#条款36绝不重新定义继承而来的non-virtual函数)论述了non-virtual函数不应该被重新定义，那么non-virtual函数中的参数也就不存在被重新定义的机会。因此这里主要针对的是virtual函数

**原因就在于，virtual函数是动态绑定，而缺省参数值却是静态绑定**。所以你可能调用了一个派生类的virtual函数，但是使用到的缺省参数，却是基类的

```
class Shape{
public:
    enum ShapeColor {Red,Green,Blue};
    virtual void draw(ShapeColor color = Red) const = 0;
};

class Rectangle : public Shape {
public:
    virtual void draw(ShapeColor color = Green) const;
    };

    class Circle : public Shape {
    public:
        virtual void draw(ShapeColor color) const;
        ...
    };

Rectangle r;
Circle c;
r.draw();// 调用Rectangle::draw，静态类型为Rectangle，所以缺省参数为Shape::Green
//c.draw();         //调用Circle::draw，静态类型为Circle，没有缺省参数，因此错误，必须显式指定！

Shape *pr = &r;
Shape *pc = &c;

// 以下为容易引起困惑的地方，函数与参数不一致
pr->draw(); // 调用Rectangle::draw,但是静态类型为Shape，所以缺省参数Shape::Red
pc->draw();         //调用Shape::draw，但是静态类型为Shape，所以缺省参数Shape::Red
```

但是，即使派生类严格遵循基类的缺省参数，也存在问题：当基类的缺省参数发生变化时，派生类的所有缺省参数也需要跟着修改。因此，**本质在于，不应该在virtual函数中使用缺省参数**，如果有这样的需求，那么这种场景就适合使用[条款35](#)中，public virtual函数的几种替代方案，比如NVI手法：


## 条款38：通过复合塑模出has-a或“根据某物实现出”

> 复合是类型间的一种关系，当某种类型的对象含有另一种类型的对象，便是这种关系

复合意味着has-a(有一个)或is-implemented-in-terms-of(根据某物实现出)

* has-a：
    ```
    class Address {...};
        class PhoneNumber {...};
        class Person{
        public:
            ...
        private:
            std::string name;
            Address address;
            PhoneNumber voiceNumber;
            PhoneNumber faxNumber;
        };
    ```

 * 根据某物实现出：
     ```
     template <class T, class Sequence = deque<T> >
     class stack{
     protected:
           Sequence c;   //底层容器
     }
     ```

上面两者情况都应该使用复合，而不是public继承。在has-a中，每个人肯定不是一个地址，或者电话。显然不能是is-a的关系。而对于后者，由于每个栈只能从栈顶压入弹出元素，而队列不同，is-a的性质是所有对基类为true的操作，对派生类也应该为true。所以stack也不应该通过public继承deque来实现，因此使用复合

## 条款39：明智而审慎地使用private继承

**private继承和public继承的不同之处**

* **编译器不会把子类对象转换为父类对象**
```
class Person{}
class Student:public Person{} // private继承
void eat(const Person& p); // 任何人都会吃
Person p; // p是人
Student s; // s 是学生
eat(p); // 没问题，p是人，会吃
eat(s);  // 错误！难道学生不是人？！
```

如果使用public继承，编译器在必要的时候可以将Student隐式转换成Person，但是private继承时不会，所以eat(s)调用失败。从这个例子中表达了，private继承并不表现出is-a的关系。实际上**private表现出的是"is-implemented-in-terms-of"的关系**

* **父类成员（即使是public、protected）都变成了private**

[条款38](#条款38通过复合塑模出has-a或根据某物实现出)提到，复合也是可以表现出"is-implemented-in-terms-of"的关系，那么两者有什么区别？

### 1）private继承

假设Widget类需要执行周期性任务，于是希望继承Timer的实现。因为Widget不是一个Timer，所以选择private继承

```
class Timer {
public:
    explicit Timer(int tickFrequency);
    virtual void onTick() const;          // 每滴答一次，该函数就被自动调用一次
};

class Widget:private Timer{
private:
    virtual void onTick() const; // 查看Widget的数据...等等
};
```

在Widget中重写虚函数onTick，使得Widget可以周期性地执行某个任务

通过private继承来表现"is-implemented-in-terms-of"关系实现非常简单，而且下列情况也只能使用这种方式：

* 当Widget需要访问Timer的protected成员时。因为对象组合后只能访问public成员，而private集成后可以访问protected成员
* 当Widget需要重写Timer的虚函数时。比如上面的例子中，需要重写onTick。单纯的复合做不到

### 2）复合

如果使用复合，上面的例子可以这样实现：

```
class Widget{
private:
    class WidgetTimer: public Timer{
    public:
        virtual void onTick() const;
    };
    WidgetTimer timer;
};
```

通过复合实现"is-implemented-in-terms-of"关系，实现较为复杂，但是有以下优点：

* 如果希望禁止Widget的子类重定义onTick。因为派生类无法访问私有的WidgetTimer类
* 可以减小Widget和Timer的编译依赖。如果是private继承，在定义Widget的文件中势必需要引入#include"Timer.h"。但如果采用复合的方式，可以把WidgetTimer放到另一个文件中，在Widget中使用WidgetTimer\*并声明WidgetTimer即可

总的来说，在需要表现"is-implemented-in-terms-of"关系时。如果一个类需要访问基类的protected成员，或需要重新定义其一个或多个virtual函数，那么使用private继承。否则，在考虑过所有其它方案后，仍然认为private继承是最佳办法，才使用它

