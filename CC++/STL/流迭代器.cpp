#include <bits/stdc++.h>
using namespace std;

ostream_iterator<string> oo {cout};
istream_iterator<string> ii {cin};
istream_iterator<string> eos{};  //表示结束
int main(){
    *oo = "Hello,";
    ++oo;
    *oo = "World!\n";
    string from, to;
    cin >> from >> to;
    ifstream is{from};
    ofstream os{to};

    set<string> b{istream_iterator<string> {is}, eos};
    copy(b.begin(), b.end(), ostream_iterator<string>{os, "\n"});

}
