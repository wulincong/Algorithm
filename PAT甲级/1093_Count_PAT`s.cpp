#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(int argc, char **argv){
    string s;
    cin >> s;
    int cnt = 0;
    vector <int> c_T(s.size() + 1, 0), c_A(s.size() + 1, 0);
    for(int i = s.size() - 1; i >= 0; i--){
        if(s[i] == 'T') {
            c_T[i] = c_T[i + 1] + 1;
            c_A[i] = c_A[i + 1];}
        else if(s[i] == 'A') {
            c_A[i] = c_A[i + 1] + 1;
            c_T[i] = c_T[i + 1];}
        else{
            c_A[i] = c_A[i + 1]; c_T[i] = c_T[i + 1];
        }

    }
    // for(int i = 0; i < s.size(); i++) cout << c_T[i] << " ";
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'P'){
            // cnt += c_A[i] * c_T[i];
            for(int j = i; c_A[j] != 0; j++){
                if(s[j] == 'A') cnt += c_T[j];
            }
        }
    }
    cout << cnt;
}
