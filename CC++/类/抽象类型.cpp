#include <bits/stdc++.h>
using namespace std;

class Container{
public:
    virtual double& operator[](int) = 0;    //纯虚函数
    virtual int size() const = 0;           //常量成员函数
    virtual ~Container() {}                 //析构函数
};

void use(Container & c){
    const int sz = c.size();
    for(int i = 0; i < sz; i++)
        cout << c[i] << '\n';
}

class Vector{

};

class Vector_container : public Container{
    vector<double> v;
public:
    Vector_container(int s): v(vector<double>(s)) {}
    ~Vector_container() {}

    double & operator[](int i) { return v[i]; }
    int size() const {return v.size();}
};