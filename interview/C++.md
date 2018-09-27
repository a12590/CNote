* **一.变量**
* 1）全局变量与static变量？（作用域、生存周期）
* 2）[static函数与普通函数的区别？](temp/C++.md#4static函数与普通函数的区别)
* 3）两个文件中声明两个同名变量？(使用了与未使用extern？)
* 4）全局数组和局部数组的初始化？
* 5）[指针和引用的区别](https://www.nowcoder.com/ta/nine-chapter/review?page=11)？（代表意义、内存占用、初始化、指向是否可改、能否为空）
* 6）[C/C++中的强制转换](https://github.com/a12590/CNote/blob/master/C++/EffectiveC++.md#%E6%9D%A1%E6%AC%BE27%E5%B0%BD%E9%87%8F%E5%B0%91%E5%81%9A%E8%BD%AC%E5%9E%8B%E5%8A%A8%E4%BD%9C)
* 7）[如何修改const变量、const与volatile](https://blog.csdn.net/heyabo/article/details/8745942)
* 8）静态类型获取与动态类型获取（[typeid](https://github.com/a12590/CNote/blob/master/C++/interview/temp/RTTI/typeid.cpp#L4)、dynamic_cast:转换目标类型必须是引用类型）
* 9) [如何比较浮点数大小？](https://blog.csdn.net/jk110333/article/details/8902707)（[直接使用==比较出现错误的例子](https://stackoverflow.com/questions/26261466/in-current-c-and-java-double-type-and-float-type-if-x-0-0-is-correct)）
* **二.函数**
* 1）重载（[参数必须不同(const修饰形参)](https://github.com/a12590/CNote/blob/master/C++/interview/temp/overload/main.cpp#L9)、重载与作用域、继承中的重载\(using\)、重载与const成员函数）
* **三.类**
    * 1）面向对象的三大特性（封装、继承、多态）
    * 2）struct和class的区别？
    * 3) [访问权限说明符](temp/C++.md/#3访问控制说明符)？（目的是加强类的封装性）
    * 4）类的静态成员（所属？静态成员函数不能声明成const、类类型的成员、定义时不能重复使用static、具有类内初始值的静态成员定义时不可再设初值）\
    * 5）构造函数相关
            - 有哪些构造函数（默认、委托、拷贝、移动）
            - 合成的默认拷贝构造函数（默认行为？什么情况下不会合成？怎么解决？如果成员包含类内初始值，合成默认构造函数会使用该成员的类内初始值初始化该成员）
            - 拷贝构造函数（调用时机、合成版的行为、explict？、为何第一个参数必须是引用类型）
            - 移动拷贝构造函数（非拷贝而是窃取资源、与noexcept?、何时合成）
            - 可否通过对象或对象的引用(指针或引用)调用
    * 6）初始值列表（顺序、效率(内置类型不进行隐式初始化故无所谓,但..)、无默认构造函数的成员,const成员,引用成员必须通过初始值列表初始化）
    * 7）赋值运算符相关
        - 拷贝赋值运算符（合成版的行为？、与delete？、自定义时要注意自赋值，参数与返回类型、大部分组合了拷贝构造函数与析构函数的工作）
        - 阻止拷贝（某些对象应该独一无二(比方说人)、C++11前:private并且不定义(试图拷贝会报链接错误)，C++11:=delete [《Effective C++:条款6》]

 - 移动赋值运算符（与noexcept？何时合成）
        - 可以定义为成员或非成员函数，定义成成员函数时第一个操作数隐式绑定到this指针
        - 不可重载的操作符有哪些？（?:，::）
    * 8）析构函数相关
        - 销毁过程的理解（delete会执行哪些操作？[逆序析构成员]
        - 为什么析构函数中不能抛出异常？（不能是指“不应该”，C++本身并不禁止[《Effective C++:条款8》]
        - 如果析构函数中包含可能抛出异常的代码怎么办？（Effective C++:条款8》）
                - 可否通过对象或对象的引用(指针或引用)调用
                - 为什么将继承体系中基类的析构函数声明为虚函数？（[《Effective C++:条款7》]
                - 不应该将非继承体系中的类的虚函数声明为虚函数（[《Effective C++:条款7》]
                - 不应该继承析构函数非虚的类（[《Effective C++:条款7》],final防止继承）
                - [防止继承的方式](https://blog.twofei.com/672/)
    * 9）[删除的合成函数]（一般函数而言不想调用的话不定义就好）
    * 10）继承相关
            - 继承体系中的构造、拷贝、析构顺序？（派生类只负责自己成员的拷贝控制，可以(换而言之非必须，如果不显示调用，会调用父类合成的默认版本)在初始值列表或函数体中调用基类相应函数）
            - 继承中的名字查找（作用域嵌套、从子类到父类查找；[成员名字的处理]
            - [成员函数体内、成员函数的参数列表的名字解析时机]
    （因此，务必将“内嵌的类型声明”放在class起始处）
            - 同名名字隐藏（如何解决？(域作用符，从指示的类开始查找)、不同作用域无法重载、using的作用？除此之外呢？）
            - 虚继承（解决什么问题？(多继承中的子对象冗余)）
    * 11）多态的实现？
    * 12）[虚函数的实现原理？对类大小的影响？](https://www.cnblogs.com/malecrab/p/5572730.html)（vtbl是一个由函数指针组成的数组，无论pb指向哪种类型的对象，只要能够确定被调函数在虚函数中的偏移值，待运行时，能够确定具体类型，并能找到相应vptr，进一步能找出真正应该调用的函数）
    * 13）为什么不要在构造、析构函数中调用虚函数？（子对象的base class构造期间，对象的类型是UNIX环境高级编程.mdbase class [《Effective C++:条款9》]
    * 14）[虚函数被覆盖？]()
    * 15）virtual函数动态绑定，缺省参数值静态绑定（[《Effective C++:条款37》]
    * 16）纯虚函数与抽象基类（[纯虚函数与虚函数、一般成员函数的选择](../C++/EffectiveC++.md#条款34区分接口继承和实现继承)）
    * 17）静态类型与动态类型（引用是否可实现动态绑定）
    * 18）浅拷贝与深拷贝（安全性、行为像值的类与行为像指针的类）
    * 19）如何定义类内常量？（enum而不是static const [《Effective C++:条款2》]
    * 20）继承与组合(复合)之间如何选择？（[《Effective C++:条款38》]
    * 21）private继承？（[《Effective C++:条款39》]
    * 22）[如何定义一个只能在堆上（栈上）生成对象的类？](https://www.nowcoder.com/questionTerminal/0a584aa13f804f3ea72b442a065a7618)
    * 23）[内联函数、构造函数、静态成员函数可以是虚函数吗？](https://www.nowcoder.com/ta/nine-chapter/review?page=24)
* **四.内存管理**
    * 1）[C++内存分区](../C++/内存分区.md)
    * 2）[new](https://github.com/a12590/CNote/blob/master/C++/C++对象模型.md#1new)和malloc的区别？（函数，运算符、类型安全、计算空间、步骤，[operator new的实现](../C++/C++对象模型.md#3operator-new和operator-delete的实现)）
    * 3）[new[]与delete[]？](../C++/C++对象模型.md#4针对数组的new语意)（步骤：如何分配内存，构建对象、如何析构与释放内存？[构造与析构](../C++/C++对象模型.md#3对象数组)）
    * 4）new带括号和不带的区别？（无自定义构造函数时，不带括号的new只分配内存，带括号的new会初始化为0）
    * 5）new时内存不足？（[《Effective C++:条款49》]
    * 6）[malloc](https://github.com/arkingc/note/blob/master/%E6%93%8D%E4%BD%9C%E7%B3%BB%E7%BB%9F/UNIX%E7%8E%AF%E5%A2%83%E9%AB%98%E7%BA%A7%E7%BC%96%E7%A8%8B.md#5%E5%AD%98%E5%82%A8%E7%A9%BA%E9%97%B4%E5%88%86%E9%85%8D)、[calloc](https://github.com/arkingc/note/blob/master/%E6%93%8D%E4%BD%9C%E7%B3%BB%E7%BB%9F/UNIX%E7%8E%AF%E5%A2%83%E9%AB%98%E7%BA%A7%E7%BC%96%E7%A8%8B.md#5%E5%AD%98%E5%82%A8%E7%A9%BA%E9%97%B4%E5%88%86%E9%85%8D)、[realloc](https://github.com/arkingc/note/blob/master/%E6%93%8D%E4%BD%9C%E7%B3%BB%E7%BB%9F/UNIX%E7%8E%AF%E5%A2%83%E9%AB%98%E7%BA%A7%E7%BC%96%E7%A8%8B.md#5%E5%AD%98%E5%82%A8%E7%A9%BA%E9%97%B4%E5%88%86%E9%85%8D)、[alloca](https://blog.csdn.net/lan120576664/article/details/38078855)，malloc的实现？
    * 7) 调用malloc函数之后，OS会马上分配内存空间吗？（不会，只会返回一个虚拟地址，待用户要使用内存时，OS发出一个缺页中断，此时，内存管理模块才会为程序分配真正的内存）
    * 8）[delete](../C++/C++对象模型.md#1new)(步骤、delete与析构、可以delete空指针、可以delete动态const对象)
    * 9）为什么要内存对齐？([性能原因、平台原因])(temp/C++.md/#1为什么要内存对齐)
    * 10）[struct内存对齐方式？](temp/alignment/struct.cpp#L1)
    * 11）如何取消内存对其？（添加预处理指令`#pragma pack(1)`）
    * 12）什么是内存泄露？如何检测与避免？（Mtrace，[valgrind](temp/C++.md/#2valgrind)）
    * 13）[智能指针相关](https://mubu.com/doc/BGwWx-huk)
        * 种类、区别、原理、能否管理动态数组
        * shared_ptr（使用、计数的变化，get()函数要注意什么）
        * unique_ptr(如何转移控制权)
        * [weak_ptr(特点、用途：可以解决shared_ptr的循环引用问题)]
    (https://www.cnblogs.com/DswCnblog/p/5628314.html)
        * 手写实现智能指针
    * 14）[实现memcpy](../数据结构与算法/算法题总结.md#1实现memcpy)
    * 15）memcpy与memmove的区别（前者不处理重叠，后者处理重叠）
    * 16）[能否使用memcpy比较两个结构体对象？](https://blog.csdn.net/peng314899581/article/details/60766892)
    * 17）实现[strlen](../数据结构与算法/算法题总结.md#1实现strlen)、[strcmp](../数据结构与算法/算法题总结.md#2实现strcmp)、[strcat](../数据结构与算法/算法题总结.md#3实现strcat)、[strcpy](../数据结构与算法/算法题总结.md#4实现strcpy)

* **五.STL**
    * 1）[顺序容器与关联容器的比较？](https://blog.csdn.net/JIEJINQUANIL/article/details/51175858)[有哪些顺序容器与关联容器？](../pic/stl-4-1.jpeg)
    * 2）[vector底层的实现](../C++/STL%E6%BA%90%E7%A0%81%E5%89%96%E6%9E%90.md#1vector)（迭代器类型为随机迭代器）？insert具体做了哪些事？[resize()](../C++/tass-sgi-stl-2.91.57-source/stl_vector.h#L209)调用的是什么？
    * 3）vector的push_back要注意什么（大量调用会伴随大量的拷贝构造与析构，内存分配与释放）
    * 4）vector的resize()与[reserve()](../C++/tass-sgi-stl-2.91.57-source/stl_vector.h#L129)（[测试程序](https://github.com/arkingc/llc/blob/master/cpp/container/vector/size.cpp#L5)）
    * 5）[如何释放vector的空间？](https://blog.csdn.net/u014774781/article/details/48197891)（swap）、[容器的元素类型为指针？](https://blog.csdn.net/u014774781/article/details/48197891)（会有内存泄露，[指针是trivial_destructor](../C++/tass-sgi-stl-2.91.57-source/stl_construct.h#L72)；也可以使用智能指针来管理）
    * 6）[vector的clear](../C++/tass-sgi-stl-2.91.57-source/stl_vector.h#L210)与[deque的clear](../C++/tass-sgi-stl-2.91.57-source/stl_deque.h#L774)（vector的erase和clear只会析构不会释放内存，deque的erase和clear不但会析构，还可能会释放缓冲区）
    * 7）[list的底层实现](../C++/STL源码剖析.md#23-list的数据结构)（迭代器类型为双向迭代器）
    * 8) [deque的底层实现](../C++/STL%E6%BA%90%E7%A0%81%E5%89%96%E6%9E%90.md#33-deque%E7%9A%84%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84)（迭代器类型为随机迭代器）

