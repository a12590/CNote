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

## 条款02：尽量以const,enum,inline替换\#define

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
* **copy构造函数**：编译器生成的版本只是单纯将来源对象的每个non-static成员变量拷贝到目标对象
* **copy assignment操作符**：。。。
* **析构函数**：版本是**non-virtual**的

[更深层次的理解](C++对象模型.md#第2章-构造函数语意学)（对象模型第2章、第5章）

以下情况编译器不会合成**copy assignment操作符**：

* **含有引用成员**：原因在于这种情况下，赋值的目的不明确。是修改引用还是修改引用的对象？如果是修改引用，禁止的。
* **含有const成员**：const对象不应该修改
* **父类的copy assignment操作符被声明为private**：无法处理基类子对象，因此也就无法合成

## 条款06：若不想使用编译器自动生成的函数，就该明确拒绝

**为什么要拒绝**？比如，房产应该是独一无二，这种情况下应该拒绝对象拷贝动作
一般情况下，不声明相应函数即可拒绝。但是编译器会为类合成一些函数，因此需要显式拒绝

还是以拒绝对象拷贝为例子，拒绝方法包括：
1、**将copy构造函数或copy assignment操作符声明为private，并且不定义**
    + 这种情况下member函数和friend函数还是可以调用，如果member函数或friend函数中执行了复制，会引发**链接错误**。可以使用一个基类，在基类中将copy构造函数或copy assignment操作符声明为private，并且继承这个基类。这样可以将**链接错误**移至**编译期**，因为尝试拷贝时，编译器会试着生成一个copy构造函数和一个copy assignment操作符，这些函数的“编译器合成版”会尝试调用其基类的对应兄弟，而那些调用会被编译器拒绝，因为private
2. **使用delete**（这个在书中没有提到）

## 条款07：为多态基类声明virtual析构函数

* **为基类声明virtual析构函数**：当派生类对象经由一个基类指针被删除，而该基类带有一个non-virtual析构函数，结果未定义
—实际执行时通常发生的是对象的derived成分没有销毁，即“局部销毁”，造成资源泄漏（因为存在这个问题，所以不要继承一个不被用作基类的类）
* **class不用作基类，不要将析构函数声明为virtual**：virtual会引入虚函数指针，这会增加空间开销，使得类无法被C函数使用，从而不再具有移植性。

<br>

## 条款08：别让异常逃离析构函数

**C++并不禁止析构函数吐出异常，但是并不鼓励这样做**

### 1）原因

如果析构函数吐出异常，程序可能过早结束（比如某个函数调用发生异常，在回溯寻找catch过程中，每离开一个函数，
这个函数内的局部对象会被析构，如果此时析构函数又抛出异常，前一个异常还没得到处理又来一个，因此一般会引起程序过早结束）。异常从析构函数中传播出去，可能会导致不明确的行为

[知乎相关描述](https://www.zhihu.com/question/28592504)

### 2）如何解决
1、**在析构函数中catch异常**，然后调用**abort终止**程序。通过abort抢先置“不明确行为”于死地
2、**在析构函数中catch异常**，然后记录该失败，即“吞掉异常”（通常是个坏主意，因为这样压制了“某些动作失败”的重要信息。但是也比担负“草率结束程序”或”不明确行为带来的风险“好）
3、重新设计接口，让客户能够在析构前主动调用可能引起异常的函数，然后析构函数中使用一个bool变量，根据用户是否主动调用来决定析构函数中是否应该调用可能引起异常的函数。。

## 条款09：绝不在构造和析构过程中调用virtual函数

如果希望在继承体系中根据类型在构建对象时候表现出不同行为，可以会想到在基类的构造函数中调用一个虚函数

```
class Transaction{
public:
    Transaction(){
        logTransaction();
    }
    virtual void logTransaction() const = 0;
};

class BuyTransaction:public Transaction{
public:
    virtual void logTransaction() const;
};

class SellTransaction:public Transaction{
public:
    virtual void logTransaction() const;
};
```

但是最终调用的virtual函数都是基类的版本。同时，因为是纯虚函数，除非定义该函数，否则将报链接错误

**在子类构造期间，virtual函数绝不会下降到派生类。取而代之，对象的作为就像隶属基类类型一样。即派生类对象的基类构造期间，对象的类型是基类而不是派生类；除此之外，若运行期间类型信息**
（如dynamic_cast和typeid），也会把对象视为基类类型（这样对待是合理的：因为子类部分尚未初始化，如果调用的是子类的虚函数，通常会访问子类部分的数据，引发安全问题）

**同样的道理也适用于析构函数。一旦派生类析构函数开始执行，对象内的派生类成员变量便呈现未定义值，所以C++视他们为不存在。进入基类析构函数后对象就成为一个基类对象**

## 条款10：令operator=返回一个reference to \*this

这是为了实现“连锁赋值”。这个协议除了适用于operator=，还适用于+=、-=、\*=

> 这只是个协议，并无强制性，如果不遵循，代码一样可以通过编译

## 条款11：在operater=中处理“自我赋值”

考虑如下Widget类：

```
class Bitmap{}
class Widget{
private:
    Bitmap *pb;
```

下面的operator=实现是一份不安全的实现，在自赋值时候会出现问题：

```
Widget&
Widget::operator=(const Widget& rhs){
    delete pb; // stop using current bitmap
    pb = new Bitmap(*rhs.pb);// start using a copy of rhs's bitmap
    return *this;
}

```
