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
struct S7:S0{int b;}; //是POD
struct S8:S1{int b;}; //不是POD
struct S9:S0, S1{}; //是POD

struct PPN{     //R6000 物理页编号
    unsigned int PFN:22;
    int : 3;
    unsigned int CCA:3;
    bool nonreachable:1;
    bool dirty:1;
    bool valid:1;
    bool global:1;
};

