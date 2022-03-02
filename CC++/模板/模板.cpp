#include <bits/stdc++.h>
using namespace std;

template <typename Container, typename Value>
Value sum(const Container& c, Value v){
    for(auto x:c)v += x;
    return v;
}

template <typename T>
class Less_than{
    const T val;
public:
    Less_than(const T & v):val(v) {}
    bool operator()(const T & x) const { return x < val; }
};

template <typename C, typename P>
int count(const C& c, P pred){
    int cnt = 0;
    for(const auto & x: c)
        if(pred(x))cnt++;
    return cnt;
}

void f(const vector<int> & vec, const list<string> & lst, int x, const string & s){
    cout << count(vec, [&](int a){return a < x;}) << endl;
    cout << count(lst, [&](const string &a){return a < s;}) << endl;
}

template <typename T, typename... Tail>
void f(T head, Tail... tail){
    cout << head << " ";
    f(tail...);
}
void f(){}  //不执行任何操作

