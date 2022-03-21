#include <bits/stdc++.h>
using namespace std;

struct Link{
    Link *prev, *next;
};

struct No_good{


    No_good member;
};

struct S0{};   //是POD
struct S1{int a;};  //是POD
struct S2{int a; S2(int aa):a(aa){}}; //不是POD（不是默认的构造函数）
struct S3{int a; S3(int aa):a(aa){}; S3(){}};  //是POD，用户自定义了默认构造函数
struct S4{int a; S4(int aa):a(aa){}; S4() = default;}; //是POD
struct S5{virtual void f();};  //不是POD（含有一个虚函数）

struct S6:S1{};   //是POD
