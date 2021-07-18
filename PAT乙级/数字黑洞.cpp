#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **argv){
    int i, a, b;
    string s;
    vector<char> v1, v2;
    cin >> i;
    while(1){
        s = to_string(i);
        v1.assign(s.begin(),s.end());
        sort(v1.begin(), v1.end());  //从小到大排序
        v2 = v1;
        reverse(v1.begin(), v1.end());

        s = ""; for( auto i : v1) s += i;  a = stoi(s);
        s = ""; for( auto i : v2) s += i;  b = stoi(s);
        i = a - b;
        for(auto i: v1) cout << i ;
        cout << " - ";
        for (auto i: v2) cout << i ;
        cout << " = " << i << endl; 
        if (i == 6174) break;
    }
    return 0;
}