#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

map<string, int> Map;

void Addword(string str){
    if(Map.count(str)){
        Map[str]++;
    }else Map[str] = 1;
}

int main(int argc, char **argv){
    string  s, t;
    int max = 0;
    getline(cin, s);
    for(int i = 0; i < s.size(); i++){
        if(! isalpha(s[i])){
            s[i] = ' ';
        }else {
            s[i] = tolower(s[i]);
        }
    }
    stringstream ss(s);
    ss >> t;
    while(ss >> t){
        Addword(t);
    }
    for(map<string, int>::iterator it = Map.begin(); it != Map.end(); it++){
        if(it->second > max) {
            max = it->second;
            t = it->first;
        }       
    }
    cout << t << " " << max;
}

