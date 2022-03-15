#include <bits/stdc++.h>
using namespace std;

vector<string::iterator> find_all(string & s, char c){
    vector<string::iterator> res;
    for(auto p = s.begin(); p != s.end(); ++p)
        if(*p == c) res.push_back(p);
    return res;
}

template<typename C, typename V>
vector<typename C::iterator> find_all(C &c, V v){
    vector<typename C::iterator> res;
    for(auto p = c.begin(); p != c.end(); ++p){
        if(*p == v) res.push_back(p);
    }
    return res;
}


int main() {
    
}