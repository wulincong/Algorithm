#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long Add(string a, string b){
    string s = a+b;
    return atoll(s.c_str());
}

bool cmp(string a, string b){
    if(a[0] != b[0]) return a[0] < b[0];
    else return Add(a, b) < Add(b, a);
}

int main(){
    int N;
    string t;
    cin >> N;
    vector<string> V;
    for(int i = 0; i < N; i++){
        cin >> t;
        V.push_back(t);
    }
    sort(V.begin(), V.end(), cmp);
    cout << atoi(V[0].c_str());
    for(int i = 1; i < N; i++){
        cout << V[i];
    }
    cout << endl;
}


