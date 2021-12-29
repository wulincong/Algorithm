#include <stdio.h>

int BST(int *A, int low, int high, int x){
    int j = 0;
    int cnt = 0;
    while (low <= high && j == 0){
        cnt++;
        printf("%d %d\n", low, high);
        int mid = (low + high) / 2;
        if(A[mid] == x) j = mid;
        else if(x < A[mid]) high = mid - 1;
        else low = mid + 1;
    }
    printf("%d", cnt);
    return j;
}

int main(){
    int A[10000];
    for(int i = 1; i <= 2000; i++) A[i] = i;
    //for(int i = 1; i <= 60; i++) printf("%d ", A[i]);
    BST(A, 1, 2000, 1000);
}

