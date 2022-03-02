#include <bits/stdc++.h>

using namespace std;

class Vector{
private:
    double * elem;
    int sz;
public:
    Vector(int s);
    ~Vector(){delete[] elem;}

    Vector(const Vector& a);  //拷贝构造函数
    Vector & operator=(const Vector& a); //拷贝赋值运算符

    Vector(Vector&& a); //移动构造函数
    Vector& operator=(Vector&& a); //移动赋值运算符

    double & operator[](int i);
    const double & operator[](int i) const;

    int size() const;
};

Vector::Vector(const Vector & a)
    :elem{new double[sz]}, sz{a.sz}{
        for(int i = 0; i < sz; i++) elem[i] = a.elem[i];
    }

Vector::Vector(Vector && a)
    :elem{a.elem},
    sz{a.sz}
{
    a.elem = nullptr;
    a.sz = 0;
}

std::vector<thread> my_threads;
thread heartbeat;


Vector init(int n){
    thread t ;
    my_threads.push_back(move(t));
}

class Shape{
public:
    Shape(const Shape &) = delete;
    Shape & operator=(const Shape&) = delete;

    Shape(Shape && ) = delete;
    Shape & operator=(Shape && ) = delete;
};