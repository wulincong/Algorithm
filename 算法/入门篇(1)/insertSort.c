#include <stdio.h>

int insert_sort(int *A, int n){
    for(int i = 1; i < n; i++){
        int key = A[i];
        int j = i -1;
        while (j >= 0 && A[j] > key){
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j+1] = key;
    }
}



int main(){
    int A[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    insert_sort(A, 10);
    for(int i = 0; i < 10; i++) 
        printf("%d ", A[i]);
}
