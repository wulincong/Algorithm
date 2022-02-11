#include <iostream>
using namespace std;

int main() {
    int K;
    cin >> K;
    int A[K], M[K], B[K];
    for( int i = 0; i < K; i++)cin >> A[i]; 
    M[0] = A[0];
    B[0] = 0;
    int maxEnd = 0, maxBegin = 0;
    for( int i = 1; i < K; i++){
        if(M[i - 1] >= 0){
            M[i] = A[i] + M[i - 1];
        }else{
            M[i] = A[i];
            maxBegin = i;
        }
        B[i] = maxBegin;
        if(M[maxEnd] < M[i]) maxEnd = i;
    }
    if(M[maxEnd] < 0) {
        cout << "0 " << A[0] << " " << A[K-1];
    }else
        cout << M[maxEnd] << " " << B[maxEnd] << " " << maxEnd << endl;
    return 0;
}
