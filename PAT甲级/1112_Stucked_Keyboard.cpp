#include <iostream>
#include <string>
#include <map>

using namespace std;

map<char, int> Map;

void mapadd(char c, int n){
    if(Map.count(c)){
        if(n < Map[c]) Map[c] = n;
    }else{
        Map[c] = n;
    }
}

int main(){
    int N;
    cin >> N;
    string s;
    cin >> s;
    char last_c = s[0];
    int cnt = 1;
    for(int i = 1; i < s.size(); i++){
        if(s[i] == last_c){
            cnt++;
        }else{
            if(cnt%N == 0) mapadd(last_c, N);
            mapadd(last_c, cnt);
            last_c = s[i];
            cnt  = 1;
        }
    }
    for(map<char, int>::iterator it=Map.begin(); it != Map.end(); it++){
        if(it->second >= N) cout << it->first;
    }

}



