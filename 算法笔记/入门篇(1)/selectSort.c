#include <stdio.h>

void select_sort(int *A, int n){
    /*
    每次从后面未排序的数组中选择最小的元素，将它追加到已排序的队列后
    具体操作就是遍历i = 0 -> n，j = i -> n, m记录最下的元素下标，
    */
    for(int i = 0; i < n; i++) {
        int m = i;
        for(int j = i+1; j < n; j++){
            if(A[j] < A[m]) m = j;
        }
        int tmp = A[m];
        A[m] = A[i];
        A[i] = tmp;
    }
}

int main(){
    int A[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    select_sort(A, 10);
    for(int i = 0; i < 10; i++) 
        printf("%d ", A[i]);
}

