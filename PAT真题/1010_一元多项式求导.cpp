#include <iostream>
#include <vector>
using namespace std;

int main(int ac, char **av){
    vector<int> Coefficients(2002,0);     //系数
    vector<int> Index(1001,0); //指数
    int a,b;  //a * x ^ b
    while(cin >> a >> b){
        Coefficients[b + 1001 - 1] = a * b;
    }
    bool flag_first = true;
    for(int i = 2001; i >= 0; i--){
        if(Coefficients[i] != 0){
            if(!flag_first) cout << " ";
            cout    << Coefficients[i] 
                    << " " 
                    << i - 1001;
            flag_first = false;
        }
    }
    if(flag_first) cout << "0 0";
}