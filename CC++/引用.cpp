#include <bits/stdc++.h>
using namespace std;

template <typename T>

class vector{
    T* elem;
public:
    T& operator[](int i) { return elem[i]; }   //返回元素的引用
    const T& operator[](int i) const { return elem[i];} //返回常量元素的引用
};

void f(){
    int var = 1;
    int & r{var};


    // int & rr = 1;   //错误
    const double & cdr = 1; //可以
}

string var {"sjdkad"};
string ff();
string & r1{var};   //左值引用
string & r2{ff()};   //错误  ff()返回值是右值
string & r3{"asdasdf"};  //错误 不可以把右值赋给非常量的引用

string && rr1{ff()};  // 正确 ff()返回值为右值
string && rr2{var};     //错误。 var为左值

const string & cr1 {"asdajklsdjl"};  //可以

template <class T>
void swap(T& a, T & b){
    T tmp{move(a)};
    a = move(b);
    b = move(tmp);
}

string s = R"(askjdk\asd)";

