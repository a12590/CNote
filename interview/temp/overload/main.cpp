//
// Created by JYF on 2018/9/24.
//

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;
/*
注：1）底层const即不能改变所指对象，所以传入常量和非常量都没有问题。
   故如果传入非常量或者指向非常量的指针，重载的函数都能调用，但是对于编译器优先选择非const版本
   传入常量或指向常量的指针时，只能选择const版本


 */

const string &shorterString(const string &s1,const string &s2);

string &shorterString(string &s1,string &s2);

int main()
{
    string s1(5,'l');
    string s2(10,'h');

    string &s3 = shorterString(s1,s2);//调用非const版本

    cout << s3 << endl;

    return EXIT_SUCCESS;
}

const string &shorterString(const string &s1,const string &s2){
    return s1.size() <= s2.size() ? s1 : s2;
}

string &shorterString(string &s1,string &s2){
    return s1.size() <= s2.size() ? s1 : s2;
}