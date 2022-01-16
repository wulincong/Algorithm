#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char **argv){
    float W, T, L, sum = 1.0;
    int A[3] = {0};
    for(int i=0; i<3; i++){
        cin >> W >> T >> L;
        if(W > T && W > L){
            sum *= W;
            A[i] = 0;
        }else if(T > W && T > L){
            sum *= T;
            A[i] = 1;
        }else{
            sum *= L;
            A[i] = 2;
        }        
    }
    sum = (sum * 0.65 - 1) * 2;
    for(int i=0; i<3; i++){
        if(A[i] == 0) cout << "W ";
        else if(A[i] == 1) cout << "T ";
        else cout << "L ";
    }
    printf("%.2f", sum);
    return 0;
}