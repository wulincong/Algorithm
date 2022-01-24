#include <iostream>
#include <string>
using namespace std;

int count_1(string & s){
    int cnt = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '1') cnt++;
    }
    return cnt;
}

int main(){
    int N, cnt = 0;
    string str;
    cin >> N;
    for(int i = 1; i <= N; i++){
        str = to_string(i);
        cnt += count_1(str);
    }
    cout << cnt << endl;
}


