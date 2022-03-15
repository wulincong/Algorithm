#include <bits/stdc++.h>
using namespace std;

struct X{};
void g(unique_ptr<X> &x){
    return;
}
void f(int i, int j){ 
    X* p = new X;
    unique_ptr<X> sp{new X};
    g(sp);
    if(i < 99) throw std::runtime_error("X");  //过早的抛出异常退出
    delete p;
}

int main(){

}