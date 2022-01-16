#include <iostream>
#include <string>
#include <cmath>
using namespace std;

long long to_decimal(string s, int radix) {
    int i = 0;
    long long sum = 0;
    for(int j = s.size() - 1; j>=0; j--) {
        if(s[j] >= '0' && s[j] <= '9') {
            sum += (s[j] - '0') * pow(radix, i);
        }else{
            sum += (s[j] - 'a' + 10) * pow(radix, i);
        }
        i++;
    }
    return sum;
}

int main(int argc, char **argv){
    string N1, N2;
    int tag, radix;
    long long  N1_decimal, N2_decimal;
    cin >> N1 >> N2 >> tag >> radix;
    if(tag == 1){
        N1_decimal = to_decimal(N1, radix);
        for(int i = 2; i <= 36; i++){
            N2_decimal = to_decimal(N2, i);
            if(N2_decimal == N1_decimal){
                cout << i << endl;
                return 0;
            }
        }
    }else{
        N2_decimal = to_decimal(N2, radix);
        for(int i = 2; i <= 36; i++){
            N1_decimal = to_decimal(N1, i);
            if(N1_decimal == N2_decimal){
                cout << i << endl;
                return 0;
            }
        }
    }
    cout << "Impossible" << endl;
    return 0;
}

