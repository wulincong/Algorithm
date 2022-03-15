#include <bits/stdc++.h>
using namespace std;

int f1(X &);     
int f2(const X &);
int f3(X);

class X{
    X(int);
    int m1();    // 成员
    int m2() const;

    friend int f1(X &);     //友元
    friend int f2(const X &);
    friend int f3(X);
};

void g(){
    // f2(99);
    // f3(99);
}

int main(){

}