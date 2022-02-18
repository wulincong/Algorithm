#include <bits/stdc++.h>

using namespace std;

map<string, int> Mars_to_Earth1, Mars_to_Earth2;
vector<string> Digist1 = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
vector<string> Digist2 = {"  ", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

int main(int argc, char **argv){
    for(int i = 0; i < 13; i++){
        Mars_to_Earth1[Digist1[i]] = i;
        Mars_to_Earth2[Digist2[i]] = i;
    }
    int N;
    cin >> N;
    string t; getline(cin, t);
    for(int i = 0; i < N; i++){
        string s;
        getline(cin, s);
        // cout << s << endl;
        if(isalpha(s[0])){ //是火星文
            stringstream ss(s);
            string a, b;
            int cnt = 0;
            ss >> a;
            if(ss >> b){
                cnt += Mars_to_Earth1[b] + Mars_to_Earth2[a] * 13;
            }else{
                cnt = Mars_to_Earth1[a];
            }
            cout << cnt << endl;
        }else{ //是地球数字
            int n = atoi(s.c_str());
            int G = n % 13;
            int S = n / 13;
            // cout << n << " " <<  G << " " << S << endl;
            if( S == 0)cout << Digist1[G] << endl;
            else if (G != 0 && S != 0) cout << Digist2[S] << " " << Digist1[G] << endl;
            else cout << Digist2[S] << endl;
        }
    }
}