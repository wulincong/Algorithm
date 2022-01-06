#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char **argv){
    int An, Bn, exp;
    float coef; 
    float Coefficients[1001];
    for (int i=0; i<1001; i++) Coefficients[i] = 0;
    cin >> An;
    for (int i=0; i< An; i++){
        cin >> exp >> coef;
        Coefficients[exp]  += coef;
    }
    cin >> Bn;
    for (int i=0; i< Bn; i++){
        cin >> exp >> coef;
        Coefficients[exp] += coef;
    }
    int cnt = 0;
    for (int i=0; i<1001; i++){
        if(Coefficients[i] != 0) cnt++;
    }
    cout << cnt;
    for(int i = 1000; i >= 0; i--){
        if(Coefficients[i] != 0) {
            printf(" %d %.1f", i, Coefficients[i]);
            cnt--;
        }
    }
    cout << endl;
    return 0;
}

