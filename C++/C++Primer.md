|**变量**|**函数**|**面向对象**|**模板与泛型编程**|**内存管理**|
|:--:|:--:|:--:|:--:|:--:|
|[变量](#ch1)<br>|||[模板与泛型编程](#ch2)<br>|[内存管理](#ch3)<br>|

# 一.变量

## 1.类整型

**使用建议**
* 使用int执行整数运算，超过范围用long long，因为long一般和int大小一样
* 浮点运算用double，float通常精度不够而且双精度和单精度的计算相差无几。

<br>

## 4.类型转换

*   **隐式转换**

    - ** 整形 ** ：多数表达式中，比int小的整形首先提升为较大的整形
    - ** 数组转化为指针 **
    - ** 指针的转化 **：0,nullptr转化为任意指针，任意指针转void
    - ** 转换时机 **：
        + 拷贝初始化
        + 算术或关系运算
        + 函数调用

*   ** 显示 **
    + **static_cast**:只要不包含底层const，都可以使用。适用将较大算术类型转化为较小的算术类型
    + **const_cast**:只能改变底层const，例如指向const的指针（指向的对象不一定是常量，
    但是无法通过指针修改）如果指向的是常量，则结果未定义
    + **reinterpret_cast**：通常为算术对象的位模式提供较低层次上的重新解释。如将
    int*转换为char*。很危险！！！
    + **dynamic_cast**:一种动态类型识别。转换的目标类型，即type，是
    指针或者左右值引用，主要用于基类指针转换成派生类类型的指针，通常需要知道转换源和目标对的类型
    失败返回或者bad_cast异常。

### 4.2 算术转换

## 8.复合类型
### 8.1 引用
* ** 本质 **：引用并非对象，它只是为对象起了另一个名字
* ** 形式 **： `int &a = b`
* 非常量引用不能绑定到字面值或表达式的计算结果
* 一般来说，引用类型和绑定的对象类型需严格匹配
* 引用本身并非对象，不能定义引用的引用

### 8.2 指针
* 指针和引用不同，指针本身是一个对象
* 因为引用不是对象，没有实际的地址，所以不能定义指向引用的指针
* 指针是一个对象，所以存在对指针的引用
* 一般来说，指针类型和指向的对象类型需严格匹配
* 编译器并不负责检查试图拷贝或以其他方式访问无效指针
* 和试图使用未经初始化的变量一样，使用未经无效指针的后果无法估计
* **空指针**：不指向任何对象（不要混淆空指针和**空类型**的指针）
    * `int *p1 = nullptr;`
    * `int *p2 = 0`
    * `int *p3 = NULL;`
* 把int变量直接赋值给指针是错误的，即使变量的值恰好是0
* **空类型** 指针用于存放任意对象的地址

### 8.3 复合类型的声明
#### 1）非数组与复合类型的声明
**从右到左分析**

```
int *&r = p;//r是一个引用，引用一个int指针p
```
```
int *p1,p2;// p1是一个int*，p2是一个int
```

#### 2）数组与复合类型的复杂申明
**从数组名字开始，由内到外分析**

* 数组与指针的复杂申明
```
int(*Parray)[10] = &arr; // Parray 是一个指针，指向一个含有10个int的数组
```
* 数组与引用的复杂申明
    ```c++
    int (&arrRef)[10] = arr; //arrRef是一个引用，引用一个含有10个int的数组
    ```
* 数组与指针及引用的混合复杂申明
    ```c++
    ​int *(&arry)[10] = ptrs; //arry是一个引用，引用一个包含10个int指针的数组
    ```
## 9.const
### 1）const对象
* const对象必须初始化，因为创建后const对象的值就不能再改变，初始值可以是任意复杂的表达式
```
const int i = get_size();// 运行时初始化
const int j = 42;// 编译时初始化
```
* 只能在const类型的对象上执行不改变其内容的操作
* 默认状态下，const对象仅仅在文件内有效。多个文件的同名const对象等同于在不同文件中定义独立的变量
* 要在多个文件间共享同一const对象，需在定义和声明加上extern

### 2）const的引用（常量引用）
* 不能修改所绑定的对象
* 和非常量引用不同，常量引用可以使用字面值或任意表达式作为初始值（原因：绑定了一个临时常量）

### 3）指针与const
* **指向常量的指针**
```
const int *a = &b;
```
* **const指针**（**常量指针**）：不能修改指针，将一直指向一个地址，因此必须初始化。但是指向的对象不是常量的话，可以修改指向的对象
```
int *const a = &b;
cosnt double * const pip = &pi;//pip是一个常量指针，指向的对象是一个双精度浮点型常量
```

### 4）顶层const与底层const
* **顶层const**：无法修改指针本身（顶层是一种直接的关系）
```
const int ci = 123;
int *const a  = &b;
```
* **底层const**：无法修改所指的对象（底层是一种间接的关系）
    * 用于声明引用的const都是底层const

## 10.constexpr与常量表达式
```
constexpr int mf = 20;// 20是一个常量表达式
constexpr int limit = mf + 1;// mf + 1 是常量表达式
const int sz = size();// 只有当size是一个constexpr函数时候，声明才正确
```
* **constexpr函数**：这种函数，编译时候就可以计算结果
* **字面值类型**：能使用constexpr声明的类型，
* constexpr的指针初始值必须是nullptr，0或存储在某个固定地址中的对象
* 一般来说，全局变量和静态局部变量的地址不变
* constexpr指针，constexpr只对指针有效，与指针所指对象无关
* `constexpr const int *p = &i; //p是常量指针，指向整形常量i`

## 11.类型别名
1、typedef：`typedef double wages;`
2、using `using SI = Sales_item;`

const与指针的类型别名使用时，还原别名来理解const的限定是错误的

## 12.auto
* 编译器根据初始值判断变量类型
* 必须初始化
* 一条语句声明多个变量（只能有一个基本类型，const int 和int不算1个类型）
```
auto i = 0,*p = &i; // 正确
auto sz = 0,pi = 3.14 // 错误
```
* 初始值为引用，类型为所引对象的类型
* auto一般会忽略掉顶层const，底层const会保留下来
* 如果希望判断出的auto是顶层，auto前加const
* 还可以将引用类型设为auto，此时原来的初始化规则仍然适用

## 13.decltype

* 希望根据表达式判断变量类型，但是不用表达式的值初始化变量
* `decltype(f()) sum = x;` `f()`并不会被调用，`sum`为`f()`的返回类型
* 引用从来都是作为其所指向对象的同义词出现，只有在decltype处是一个例外
* 如果表达式的结果对象能作为一条赋值语句的左值，则表达式将向decltype返回一个引用类型
```
decltype(*p) c;//错误，c是int &，必须初始化
```
* 变量加上括号会被编译器视为一个表达式
```
decltype((i)) d;//错误，d 是int&，必须初始化
```

# 模板与泛型编程
## 1.模板函数
```
template <typename T>
int compare(const T &v1,const T &v2)
{
    if(v1 < v2) return -1;
    if(v1 > v2) return 1;
    return 0;
}
```
当调用一个函数模板时候，编译器用函数实参来为我们推断模板实参；
泛型编写的原则：
1、模板中的函数参数是const的引用（保证了函数可以用于不能拷贝的类型。同时，如果compare用于处理大对象，这种设计策略可以使得函数运行更快）
2、函数中的条件判断仅仅使用<比较运算（如果编写代码时候，只使用<运算符，就降低了compare函数对要处理的类型的要求）

> 函数模板可以声明为inline或constexpr的，如同非模板函数一样。inline或constexpr说明父放在模板参数列表之后，返回类型之前

### 1.1 模板参数
* 在模板定义中，模板参数列表不能为空
* 模板参数的名字没有什么内在的含
* 一个模板参数名的可用范围是在其声明之后，至模板声明或定义结束之前。模板参数会隐藏外层作用域中声明的相同的名字，模板内不能重用模板参数名
* 与函数参数相同，声明中的模板参数的名字不必与定义中相同
* typename和class并没有什么不同，typename可能更直观，因为class可能会让人觉得能使用的类型必须是类类型

#### 1）模板类型参数
**用来指定返回类型或函数类型，以及在函数体内用于变量声明或类型转换**

```
template<typename T> T foo(T* p)
{
    T tmp = *p;
    return tmp;
}
```
#### 2）非类型模板参数
```
template<unsigned N,unsigned M>
int compare(const char (&p1)[N],const char (&p2)[M])
{
    return strcmp(p1,p2);
}
```

* 第一个非类型模板参数标识第一个数组的长度
* 第二个非类型。。。。。。。二。。。。。。

### 1.2 函数形参
模板函数的**形参**中可以含有正常类型。即，不一定全必须是模板类型：
```
template<typename T> ostream &print(ostream &os,const T &obj)
{
    return os << obj
}
```

### 1.3 成员模板
#### 1）普通类的成员模板

```
class DebugDelete{
public:
    DebugDelete(std::ostream &s = std::cerr):os(s){}
    template<typename T> void operator() (T *p) const
    {
        os << "deleting unique_ptr" << std::endl;
        delete p;
    }
private:
    std::ostream &os;
}
```

#### 2）类模板的成员模板
类和成员各自有自己的独立的模板参数

```
template <typename T> class Blob{
    template <typename It> Blob(It b,It e);
}
```

在类定义成员模板时候，必须同时为类模板和成员模板提供模板参数
```
template <typename T>
template <typenmae It>
Blob<T>::Blob(It b,It e):data(){} // T & It
```

实例化成员模板
```
int ia[] = {0,1,2,3,4,5,6,7,8,9};
vector<long> vi = {0,1,2,3,...};
list<const char*> w = {"now","is","the"};
Blob<int> al(begin(ia),end(ia)); //数组
Blob<int> a2(vi.begin( ),vi.end( )); //vector
Blob<string> a3(w.begin( ),w.end( )); // list
```

## 2.类模板
```
template <typename T> class Blob{
    //typename告诉编译器size_type是一个类型而不是一个对象
    typedef typename std::vector<T>::size_type size_type;
}
```

### 2.1 与模板函数的区别
* **编译器不能为类模板推断模板参数类型**

### 2.2 模板类名的使用

#### 1）类内使用不需要指明<T>
```
BlobPtr& operator++();
```

当处于一个类模板的作用域中时，编译器处理模板自身引用时候就好像我们已经提供了与模板参数匹配的实参一样

#### 2）类外使用需要指明<T>
```
template<typename T>
BlobPtr<T> BlobPtr<T>::operator++(int){

}
```

由于位于类作用域之外，必须指明返回类型是一个实例化的BlobPtr，它所用类型与类实例化所用类型一致

### 2.3 类模板的成员函数
类外定义成员函数时候要加`template<typename T>`。类模板的成员函数具有和模板相同的模板参数。因此，
定义在类模板之外的成员函数就必须以`template`开始，

```c++
template <typename T>
ret-type Blob<T>::member-name(parm-list)
```

### 2.4 类型成员

假定T是一个模板类型参数，当编译器遇到类似T::mem这样的代码时，它不会知道mem是一个类型成员还是一个static数据成员，直至初始化时才会知道。但是，为了处理模板，编译器必须知道名字是否表示一个类型。例如，假定T是一个类型参数的名字，当编译器遇到如下形式的语句时：
```c++
T::size_type *p;
```

它需要知道我们是整在定义一个名为`p`的变量还是一个名为`size_type`的static数据成员与名为`p`的变量相乘

默认情况下，C++假定通过作用域运算符访问的名字不是类型。因此，如果我们希望使用一个模板类型参数的类型成员，就必须显示告诉编译器该名字是一个类型。通过关键字`typename`来实现这一点

### 2.5 类模板和友元

#### 1）普通类中将另一模板类声明为友元

```
template <typename T> class Pal;

class C{
    //用类C实例化的Pal是C的一个友元
    friend class Pal<C>;
    // Pal2的所有实例都是C的友元
    template <typename T> friend class pal2；
};
```

#### 2）模板类中将另一模板类声明为友元

```c++
template <typename T> class Pal;
​
template <typename T> class C2 {
    //C2的每个实例将相同实例化的Pal声明为友元​
    friend class Pal<T>;
    //Pal2的所有实例都是C2的每个实例的友元
    template <typename X> friend class Pal2;​
​};​​
```

为了让所有实例成为友元，友元声明中必须使用与类模板本身不同的模板参数（上面的X）

#### 3）令模板自己的类型参数成为友元

```c++
template <typename T> class Bar{
    //将访问权限授予用来实例化Bar的类型
    ​friend T;
​};​
```

对于某个类型Foo，Foo将成为Bar<Foo>的友元...​

### 2.6 模板类型别名

类模板的一个实例化定义了一个类类型，可以定义一个typedef来引用实例化的类：

```c++
typedef Blob<string> StrBlob;
```

### 2.7 类模板的static成员

* **static属于每个实例化的类类型，而不是类模板。即，每个实例化的类都有一个自己对应的static成员**
* **模板类的每个static成员必须有且只有一个定义。但是，类模板的每个实例都有一个独有的static对象**

```
template <typename T>
size_t Foo<T>::ctr = 0;
```

可通过类类型对象或作用域运算符访问：

```
Foo<int> f1;
auto ct = Foo<int>::count();
ct = f1.count();
```

只有使用时才会实例化

## 3.模板编译
### 3.1 实例化声明
形式：`extern template declaration`

```
extern template class Blob<string>;
extern template int compare(const int&,const int&);
```

当遇到external模板声明时候，不会在本文本中生成实例化代码。将一个实例化声明为extern就表示承诺在程序其他位置 有该实例化的一个定义。对于一个给定的实例化版本，可能有多个extern声明但是必须只有一个定义

### 3.2 实例化定义

```c++
template declaration
template int compare(const int &,const int&);
​template class Blob<string>;​
```

* **类模板的实例化定义会实例化该模板的所有成员**
* **所用类型必须能用于模板的所有成员**：与处理类模板的普通实例化不同，编译器会实例化该类的所有成员。即使我们不使用某个成员，它也会被实例化。因此，我们用来显示实例化一个类模板的类型，必须能用于模板的所有成员

## 4.模板参数

### 4.1 默认模板实参

#### 1）模板函数
```c++
template <typename T,typename F = less<T>>
int compare(const T &v1,const T &v2,F f = F( ))
{
    if(f(v1,v2)) return -1;
    if(f(v2,v1)) return 1;
    return 0;​​​
}​​​
```

和函数默认实参一样，所有提供了默认实参的形参右边的形参都需要提供默认实参​

#### 2）类模板

```c++
template <class T = int> class Numbers {
public:
    Numbers(T v = 0) : val(v) { }
    private:
    T val;​​​​
​};​

Numbers<long double> lots_of_precision;
Numbers<> average_precision;            //空<>表示希望使用默认类型；​​
```

### 4.2 模板实参推断

#### 1）函数模板的参数转换

* **模板类型参数的类型转换**：将实参传递给带模板类型的函数形参时，能够自动应用的类型转换只有**const转换**及**数组或函数到指针的转换**
    * **const的转换**
        * 可以将一个const对象传递给一个非const的非引用形参
            ```c++
            template <typename T> fobj(T,T);
            string s1("a value");
            const string s2("another value");​
            ​​​fobj(s1,s2); //正确；
            ```
            fobj调用中，传递了一个string和一个const string。虽然这些类型不严格匹配，但两个调用都是合法的，由于实参被拷贝，因此原对象是否是const没有关系；​
        * 可以将一个非const对象的引用(或指针)传递给一个const的引用(或指针)形参
            ```c++
            template <typename T> fref(const T&,const T&);​
            string s1("a value");
            const string s2("another value");
            fref(s1,s2); //正确；
            ```
            在fref调用中，​​​参数类型是const的引用。对于一个引用参数来说，转换为const是允许的，因此合法；
    * **非引用类型形参可以对数组或函数指针应用正常的指针转换**
        ```c++
        template <typename T> fobj(T,T);
        template <typename T> fref(const T&,const T&);​
        int a[10],b[42];​
        fobj(a,b); //调用fobj(int*,int*)
        fref(a,b); //错误，数组类型不匹配；
        ```
        ​​​​​​在fobj调用中，数组大小不同无关紧要，两个数组都被转换为指针。fobj中的模板类型为Int\*；但是，fref调用是不合法的，如果形参是一个引用，则数组不会转换为指针。a和b的类型不匹配
* **普通类型参数的类型转换**：模板函数可以有用普通类型定义的参数，即，不涉及模板类型参数的类型。这种函数实参不进行特殊处理，这些实参执行正常类型的转换

#### 2）显示实参

为什么需要显示实参？编译器无法推断出模板实参的类型。假设定义如下模板:

```c++
​template <typename T>
T sum(T,T);​
```

​则调用sum时，必须要求传入相同类型的参数，否则会报错。因此可以按这种方式定义模板：

```c++​
​​template <typename T1,typename T2,typename T3>
T1 sum(T2,T3);​​
```

但是，这种情况下，无论传入什么函数实参，都无法推断T1的类型。因此，每次调用sum时，调用者必须为T1提供一个显示实参：

```c++
auto val3 = sum<long long>(i,lng);​
```

这个调用显示指定了T1的类型，而T2和T3的类型则由编译器从i和lng的类型判断出来

**显示实参配对顺序：由左至右。只有尾部参数的显示模板实参可以忽略，但必须能推断出来**

因此，如果按找这种形式定义模板：

```c++
template <typename T1,typename T2,typename T3>
T3 sum(T2,T1);
```

则总是必须为所有三个形参指定参数。希望控制模板实例化

对于sum模板，如果保留原有的设计：`template T sum(T,T)` 则当函数调用传入不同类型的参数时，我们必须放弃参数类型推断，采取控制模板实例化的方式来调用：`sum<int>(long,1024);` 这种情况下，会实例化一个`int sum(int,int)`的函数，传入的参数都会按照内置类型的转换规则转换为int

#### 3）尾置返回类型与traits

当我们希望用户确定返回类型时，用显示模板实参表示模板函数的返回类型是很有效的。在其他情况下，要求显示指定模板实参会给用户增添额外负担，而且不会带来什么好处：

```c++
template <typename It>
??? &fcn(It beg,It end)
{
    //处理序列
    return *beg;
}​​​​​​
```

在这个例子中，并不知道返回结果的准确类型，但知道所需类型是所处理的序列的元素类型;我们知道函数应该返回`*beg`，可以使用`decltype(*beg)`来获取此表达式的类型。但是在编译器遇到函数的参数列表之前，`beg`是不存在的。所以必须使用尾置类型：


    ​​template <typename It>
    auto fcn(It beg,It end) -> decltype(*beg)
    {
        //处理序列
        return *beg;//返回序列中一个元素的引用
    }​​​​​​

也可以使用标准库的类型转换模板。​可以使用`remove_reference`来获得元素类型。这个模板有一个模板类型参数和一个名为type的成员。如果用一个引用类型实例化这个模板，则type将表示被引用的类型。如果实例化`remove_reference<int&>`，则type成员将是int。因此，可以通过下列模板满足需求：

```c++
template <typename It>
auto fcn2(It beg,It end) ->
typename remove_reference<decltype(*beg)>::type
{
    ​ //处理序列
    return *beg;
}​​​​​​
```

#### 4）函数指针和实参推断

用一个函数模板初始化一个函数指针或为一个函数指针赋值时，编译器使用指针的类型来推断模板实参

```c++
template <typename T> int compare(const T&,const T&);
int (*pf1)(const int&,const int&) = compare;
```

pf1中参数的类型决定了T的模板实参的类型。如果不能从函数指针类型确定模板实参，则产生错误：

```c++
void func(int(*)(const string&,const string&));​​​​
void func(int(*)(const int&,const int&));​​​​​
func(compare); //错误，使用那个实例?
```

对于这种情况，可以使用显示模板实参：

```c++
func(compare<int>);​​​
```

#### 5）引用与实参推断

非常重要的是记住两个规则：

1. 编译器会应用正常的引用绑定规则；
2. const是底层的，不是顶层的；​​

当一个函数的参数是模板类型参数的一个普通(左值)引用时，绑定规则告诉我们，只能传递给它一个左值：

```c++
​template <typename T> void f1(T&);
f1(i);  //i是int，T推断为int；
f1(ci); //ci是const int，T推断为const int；
f1(5);​​​  //错误
```

如果参数类型是const T&，正常的绑定规则告诉我们可以传递给它任何类型的实参：一个对象，临时对象或字面值常量​：

```c++
​​template <typename T> void f2(const T&);
f2(i); //i是int，T推断为int；
f2(ci); //ci是const int，但T推断为int；
f2(5); //T推断为int；​
```

当参数是一个右值引用时，正常绑定规则告诉我们可以传递给它一个右值：

```c++
template <typename T> void f3(T&&);
f3(42); //实参是int型的右值，T推断为int；​​
```

引用折叠：

​1. 如果将一个左值传递给函数的右值引用参数，且此右值引用指向模板类型参数(如:T&&)时，编译器推断模板的类型参数为左值引用类型
2. 如果因为1.间接的创建了一个引用的引用，则引用形参了“折叠”、则：
    * 右值引用的右值引用会被折叠成右值引用
    * 其它情况下都折叠成左值引用

因此，对于前面的f3：

```c++
f3(i)​; //i是左值，T推断为int&，T&&被折叠成int &；
f3(ci); //​​​​​ci是左值，T是const int&；
```

​​因此，如果模板参数类型为右值引用，可以传递给它任意类型的实参

**右值引用的问题**：因为可以传递任意实参，引用折叠会导致T被推断为引用或非引用类型，所以函数内使用这个类型在传入不同参数时可能产生不同结果，此时，编写正确的代码就变得异常困难；

**右值引用的使用场景**：因为上述问题，所以右值引用主要应用于两个场景

1. **模板转发其实参**：当使用右值引用作为模板参数时，如果T被推断成普通类型(即非引用)，可以通过std::forward<T>保持其右值属性，会返回一个T&&。如果被推断成一个(左值)引用，通过引用折叠，最终也还是会返回T&；因此，当用于一个指向模板参数类型的右值引用函数参数(T&&)时，forward会保持实参类型的所有细节
2. **模板被重载**

<br>

## 5.重载与模板

包含模板的函数匹配规则：

1. **候选函数包括所有模板实参推断成功的函数模板实例**
    ```c++
    template <typename T> string debug_rep(const T &t) {...}
    template <typename T> string debug_rep(T *p) {...}
    ​​string s("hi");
    //第二个模板实参推断失败，所以调用第一个模板；
    cout << debug_rep(s) << endl;
    ```
2. **可行函数按类型转换来排序**
3. **如果恰好有一个比其他提供更好的匹配则使用该函数**
    ```c++
    template <typename T> string debug_rep(const T &t) {...}
    template <typename T> string debug_rep(T *p) {...}
    string s("hi");
    //两个模板都能匹配：
    //第一个模板实例化debug_rep(const string*&)，T被绑定到string*；
    //第二个模板实例化debug_rep(string*)，T被绑定到string；​​​
    //但由于第一个实例化版本需要进行普通指针到const指针的转换，所以第二个更匹配；​
    cout << debug_rep(&s) << endl;​​​​
    ```
4. **如果有多个函数提供“同样好的”匹配**
    * 同样好的函数中只有一个是非模板函数，则选择此函数
        ```c++
        template <typename T> string debug_rep(const T &t) {...}
        template <typename T> string debug_rep(T *p) {...}
        string debug_rep(const string &s) {...}​​
        ​​string s("hi");
        //以下调用有两个同样好的可行函数：
        //第一个模板实例化debug_rep<string>(​const string &)，T被绑定到string；
        //非模板版本debug_rep(const string &s)；
        //编译器会选择非模板版本，因为最特例化；​​
        ​cout << debug_rep(s) << endl;
        ​```
    * 同样好的函数中全是模板函数，选择更“特例化的模板”
        ```c++
        template <typename T> string debug_rep(const T &t) {...}
        template <typename T> string debug_rep(T *p) {...}
        ​​string s("hi");
        ​const string​ *sp = &s;
        //以下调用两个模板实例化的版本都能精确匹配：
        //第一个模板实例化debug_rep(​const string *&)，T被绑定到string*；
        //第二个模板实例化debug_rep(const string *)，T被绑定到const string；​
        //我们可能觉得这个调用是有歧义的。但是，根据重载函数模板的特殊规则，调用被解析为debug_rep(T*)，即更特例化的版本；
        //如果不这样设计，将无法对一个const的指针调用指针版本的debug_rep。
        //问题在于模板debug_rep(const T&)本质上可以用于任何类型，包括指针类型。此模板比debug_rep(T*)更通用，后者只能用于指针类型；​​
        ​cout << debug_rep(sp) << endl;
        ```
    * 否则，调用有歧义

<br>

## 6.可变参数模板

**参数包**：

* **模板参数包**：
    `template<typename T,typename... Args>`
    Args为模板参数包，class...或typename...指出接下来的参数表示零个或多个类型的列表，一个类型名后面跟一个省略号表示零个或多个给定类型的非类型参数的列表；​​
* **函数参数包**
    ```c++
    template <typename T,typename... Args>
    void foo(const T &t,const Args& ... rest);
    ```
    rest为函数参数包

**使用参数包**：

* `sizeof...` 获取参数包大小。可以使用`sizeof...`运算符获取包中元素的数目
* **扩展包**：扩展一个包就是将包分解为构成的元素，对每个元素应用模式，获得扩展后的列表，通过在模式右边放一个省略号来触发扩展操作：
    ```c++
    template <typename T,typename... Args>
    ostream& print(ostream &os,const T &t,const Args&... rest) //扩展Args
    ​​​​{
        os << t << ​", ";
        return print(os,rest...); //扩展rest
    }​​
    ```
    扩展中的模式会独立地应用于包中的每个元素：
    ```c++
    debug_res(rest)... 是对包rest的每一个元素调用debug_res；
    debug_res(rest...) 是调用一个参数数目和类型与rest中元素匹配的debug_rest；​​​
    ```

**转发包参数**：

新标准下，可以组合使用可变参数模板与forward机制来编写函数，实现将其参数不变地传递给其他函数：

```c++
template <typename... Args>
void fun(Args&&... args) //将Args扩展为一个右值引用的列表
{
    //work的实参既扩展Args又扩展args
    work(std::forward<Args>(args)...);​​
}​​​​
```

<br>

## 7.模板特例化

编写单一模板，使之对任何可能的模板实参都是最合适的，都能实例化，这并不总是能办到。当我们不能（或不希望）使用模板版本时，可以定义类或函数模板的一个特例化版本

一个特例化版本本质上是一个实例，而非函数名的一个重载版本。因此，特例化不影响函数匹配；

* **函数模板特例化**
    ```c++
    template <typename T> int compare(const T&,const T&);
    //compare函数模板的通用定义不适合字符指针的情况，
    //我们希望compare通过strcmp比较两个字符指针而非比较指针值；
    template <>
    int compare(const char* const &p1,const char* const &p2​)
    {
        return strcmp(p1,p2);
    ​}​​​​
    ​```
    当定义一个特例化版本时，函数参数类型必须与一个先前声明的模板中对应的类型匹配。这个特例化版本中，`T`为`const char*`，​先前声明的模板要求一个指向此类型const版本的引用。一个指针类型的const版本是一个常量指针而不是指向const类型的指针。需要在特例化版本中使用的类型是`const char* const &`，即一个指向`const char`的const指针的引用；
* **类模板特例化**
    ```c++
    template <>
    struct 模板类名<Sales_data>
    {
        ...​
    }​​​
    ```
    定义了某个模板能处理Sales_data的特例化版本
* **类模板（偏特化）部分特例化**：与函数模板不同，类模板的特例化不必为所有模板参数提供实参。可以只提供一部分而非所有模板参数，或是参数的一部分而非全部特性。部分特例化本身是一个模板，**部分特例化版本的模板参数列表是原始模板的参数列表的一个子集或者是一个特例化版本**
    ```c++
    //原始的，最通用的版本
    template <class T> struct remove_reference
    ​​ { typedef T type;​ };
    //部分特例化版本，将用于左值引用和右值引用
    template <class T> struct remove_reference<T&>
    { typedef T type; };​
    template <class T> struct remove_feference<T&&>
    { typedef T type; };
    //用例
    int i;
    remove_reference<decltype(42)>::type a;           //decltype(42)为int，使用原始模板​；
    remove_reference<decltype(i)>::type b;            //decltype(i)为int&，使用第一个部分特例化版本；​
    ​remove_reference<decltype(std::move(i))>::type c;​​​​​​​​​​​​​​​ //decltype(std::move(i))为int&&，使用第二个部分特例化版本；
    ```
* **特例化成员而非类**
    ```c++
    template <>
    void Foo<int>::Bar( )
    {
        //进行应用于int的特例化处理；​​​
    }
    Foo<string> fs; //实例化Foo<string>::Foo( );
    fs.Bar( );      //实例化Foo<string>::Bar( );
    Foo<int> fi;    //实例化Foo<int>::Foo( );
    fi.Bar( );      //使用特例化版本的Foo<int>::Bar( );
    ```

<br>
<br>

# 内存管理

## 1.new和delete

### 1.1 new

#### 1）动态分配单个对象

初始化：

```
int *p1 = new int;
int *p2 = new int();
int *p2 = new int(1024);
string *ps = new string(10,'9');

// 若obj是一个int，则p1是int*
// 不能用{..}代替（obj）包含多个对象
auto pp1 = new auto(obj);
```

动态分配const对象：
* 必须初始化
* 不能修改指向的对象，但是能delete销毁这个动态分配的const对象

```
const int *pci = new const int(1024);
const string *pcs = new const string;
```

内存消耗：

* 内存不足，new会失败
* 抛出类型为bad_alloc的异常
* `new(nothrow) T` 可以阻止抛出异常

#### 2）动态分配多个对象

使用注意：
* 动态分配数组的类必须定义自己版本的拷贝、复制，销毁对象的操作

理解

* 通常称`new T[]`分配的内存为"动态数组"某种程度上有误导
* 返回的并不是一个"数组类型"的对象，而是一个“数组元素类型”的指针
* 即使使用类型别名也不会分配一个数组类型的对象

**不能创建大小为0的动态数组，但当`[n]`中`n`为0时候，是合法的。此时new返回一个合法的非空指针，次指针保证与new返回的其他任何指针都不同，就像尾后指针一样可以进行比较操作，，加0，减0，不能解引用**

初始化

```
int *pia = new int[get_size()];
int *p1 = new int[42];

//为上面的等价调用
typedef int arr[42];
int *p = new arr;

int *p1 = new int[42]();//值初始化

int *p3 = new int[5]{1,2,3,4,5};
```

### 1.2 delete

* delete单个对象：`delete p;`
* delete动态数组：`delete[] pa;`
    - 不管分配时候有没有用类型别名，delete时候都要加上`[]`
    - 逆序销毁
    - `[]`指示编译器指向的是一个数组的首元素

注意：
* 不要delete非new分配的对象
* 不要重复delete
* 可以delete空指针
* 可以delete动态分配的const对象

> 通常情况下，编译器不能分辨一个指针指向的是静态的还是动态分配的对象。类似地，编译器也不能分辨一个指针所指向的内存是否已经被释放了。对于这些delete表达式，大多数编译器能通过，尽管它们是错误的。这些错误delete的结果是未定义的

**空悬指针**：指向原本存在数据现在已经失效的内存的指针

* 当delete一个动态分配的对象后，原本指向这个对象的指针就变成了空悬指针
* 防止使用空悬指针（只能保证这个指针不会再访问无效内存，但是可能也还有其他指针也指向这块分配的内存，他们在delete后也可能会访问）
    - 在即将离开指针作用域时候delete：这样之后，当离开作用域后，这个指针就销毁了，而在delete前，指针指向的内存是有效的
    - delete后赋值为空指针nullptr

<br>

## 2.智能指针

### 2.1 通用操作

> 以下操作支持shared_ptr和unique_ptr

* 创建
```
shared_ptr<T> sp;
unique_ptr<T> up;
```
* 作为条件：`p`
* 访问指向的对象：`*p`
* 获取保存指针：`p.get()`
    - 不要delete get()返回的指针，假设delete没有问题，在引用计数为0时，智能指针会重复delete
    - 如果p是shared_ptr，不要用get()返回的指针初始化另一个shared_ptr，这样不会递增引用计数，当新建智能指针销毁后，这个动态对象就被释放了
* 交换
 ```c++
    swap(p,q);
    p.swap(q);
    ```

### 2.2 shared_ptr
#### 1）创建：

* 调用函数make_shared
    - `make_shared<T>(args)`：推荐使用。args用于初始化指向的对象，不传参数时候“值初始化”
    ```
    shared_ptr<int> p1 = make_shared<int>(42);
    shared_ptr<string> p2 = make_shared<string>(10,'9');
    shared_ptr<int> p3 = make_shared<int>();
    ```

* 调用构造函数
    - `shared_ptr<T> p(q)`
        + **q为shared_ptr时候，会递增q的引用计数**
        + **构造函数为explicit，如果q不是一个智能指针，必须直接初始化，此时q必须能转化为T\***,如`shared_ptr<int> p(new int(1024))`
        + **如果q不是一个指向动态内存的指针，需要自定义释放操作**（shared_ptr默认使用delete释放所指动态对象，如果指针不指向动态内存，不能delete）
        + **q不是智能指针时候，这种方式构造临时shared_ptr很危险**（比如一个函数参数为shared_ptr，由于explicit，因此不能隐式转换）


#### 2）赋值

```c++
p = q;  //递增q引用计数，递减p引用计数
```

#### 3）重置

```
 1）若p是唯一指向其对象的shared_ptr，则释放对象；
 2）​将p置为空；
p.reset();

#### 4）状态
```
//返回与p共享对象的智能指针数量；可能很慢，主要用于调试
p.use_count();

//若use_count()为1则返回true，否则返回false
p.unique();
```

### 2.3 unique_ptr

#### 1）初始化

```
unique_ptr<T> u1;//创建一个空的unique_ptr
unique_ptr<T D> u2; //D为自定义释放操作类型
```

#### 2）赋值与拷贝
只有在unique_ptr即将销毁时候才能赋值或拷贝，如：当函数返回一个局部unique_ptr时

#### 3）交出控制权
```c++
//返回指针，放弃对指针的控制权，并将u置为空
//不会释放，主要目的在于切断与原来管理对象的联系，将其交由其它unique_ptr来管理
u.release()

p.release()            //内存泄露
auto pp = p.release()  //要记得delete pp​​​​​
```

#### 4）释放

```
u = nullptr;        //释放u指向的对象，将u置为空；
u.reset();          //释放u指向的对象，并将u置为空；
u.reset(q);         //释放u指向的对象，转为控制指针p指向的对象
u.reset(nullptr);   //释放u指向的对象，并将u置为空；
```

#### 5）管理动态数组

**shared_ptr不能直接管理动态数组，如果要用shared_ptr来管，须提供自定义的删除操作，因为默认情况下shared_ptr使用delete销毁所指对象。
即使如此，也不能用下标访问每个元素，需要用get，unique可以用下标来访问。**

```c++
unique_ptr<int[]> up(new int[10]); //创建

up.release();    //放弃对指针的控制权，并将u置为空（不会释放。测试如此，和书本不同）

up[i];           //返回位置i处的对象，左值；
```

### 2.4 weak_ptr

#### 1）初始化

```
// 空，可以指向类型为T的对象
weak_ptr<T> w;
// 与shared_ptr sp 指向相同对象的weak_ptr，T必须能转换为sp指向的类型
weak_ptr<T> w(sp);
```

#### 2）赋值

```
w = p; // p是shared_ptr或weak_ptr，赋值后w和p共享对象
```

#### 3）重置

```c++
w.reset();     //将w置为空（不会释放对象）
```

#### 4）状态

```c++
//返回与w共享对象的“shared_ptr”的数量
w.use_count();

//如果共享对象的"shared_ptr"为0(没有共享对象的shared_ptr)，则返回true，否则返回false
w.expired();
```

#### 5）访问

```c++
//获取shared_ptr
//  如果没有共享对象的shared_ptr，则返回一个空的shared_ptr；
//  否则返回一个指向共享对象的shared_ptr；
//这种访问方式提供了对动态对象的安全访问；​
w.lock();
```

