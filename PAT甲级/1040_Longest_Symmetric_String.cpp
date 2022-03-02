#include <iostream>
#include <string>
using namespace std;

int C[1005];

bool is_Symmetric(int beg, int end, string s) {
    if(beg < 0) return false;
    for(int i = beg; i < (beg+end) / 2; i++) {
        if(s[i] != s[end - i + beg]) return false;
    }
    return true;
}

int main(){
    string str;
    getline(std::cin, str);
    // if(is_Symmetric(0, str.size() - 1, str)) cout << "True";
    int cmax = 0;
    for(int i = 1; i < str.size(); i++){
        // cout << i - C[i-1] - 2 << " " << i << endl;
        if(is_Symmetric(i - C[i-1] - 2, i, str))C[i] = C[i - 1] + 2;
        else C[i] = 0;
        if(C[i] > cmax) cmax = C[i];
    }
    cout << cmax + 1 << endl;
    // for(int i =0; i < str.size(); i++) cout << C[i] << " ";
}

