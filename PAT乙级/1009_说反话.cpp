#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int main(int argc, char **argv){
    // vector<string> S(20);
    // int n = 0;
    // string s;
    // while(cin >> s){
    //     S.push_back(s);
    //     n++;
    // }
    // auto it = S.begin();
    // it = it + n;
    // for(; it != S.begin(); it--){
    //     cout << *it << " ";
    // }
    // cout << *S.begin();


    stack<string> v;
    string s;
    while(cin >> s) v.push(s);
    cout << v.top();
    v.pop();
    while(!v.empty()) {
        cout << " " << v.top();
        v.pop();
    }
    return 0;

}