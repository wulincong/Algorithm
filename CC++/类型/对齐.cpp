#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv){
    auto ac = alignof('c');
    cout << "char " << ac << endl;
    auto ai = alignof(1);
    cout << "int " << ai << endl;
    auto ad = alignof(2.0);
    cout << "double " << ad << endl;
    int a[50];
    auto aa = alignof(a);
    cout << "int[50] " << aa << endl;
    cout << sizeof(1.0) << endl;
}