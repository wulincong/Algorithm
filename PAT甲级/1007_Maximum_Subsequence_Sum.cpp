#include <iostream>
using namespace std;

int Sum(int *A, int begin, int end){
    int s = 0;
    for(int i = begin; i <= end; i++){
        s += A[i];
    }
    return s;
}

int main() {
    int K;
    cin >> K;
    int A[10000];
    for( int i = 0; i < K; i++){
        cin >> A[i];
    } 

    int maxSum = 0, begin = 0, end = K;
    for(int i = 0; i < K; i++){
        for(int j = i; j < K; j++){
            int c = Sum(A,i,j);
            if( c > maxSum){
                maxSum = c;
                begin = i;
                end = j;
            }
        }
    }
    if(begin == 0 && end == K){
        cout << 0 << " " << A[0] << " " << A[K-1];
    }
    else cout << maxSum << " " << A[begin] << " " << A[end];
    return 0;
}

