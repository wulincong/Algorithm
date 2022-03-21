#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv){
    cout << "long long = " << sizeof(long long) << endl;
    cout << "long = " << sizeof(long) << endl;
    cout << "float = " << sizeof(float) << endl;
    cout << "double = " << sizeof(double) << endl;
    cout << "int * = " << sizeof(int*) << endl;
    cout << "char = " << sizeof(char) << endl;
    static_assert(4 <= sizeof(int), "int is too small");
    char c = -128;
    cout << int{c};
}