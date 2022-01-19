#include <stdio.h>
#define MAX 
int margeSort(int *A, int p, int q);
int Marge(int *A, int p, int q, int r);

int main(int argc, char *argv[]){
    int A[10] = {6,2,3,2,1,5,7,8,11,10,};
    for(size_t i = 0; i < 10; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
    margeSort(A,0,9);
    for(size_t i = 0; i < 10; i++){
        printf("%d ", A[i]);
    }
    return 0;
}


int margeSort(int *A, int p, int r){
    if(p<r){
        int q = (p+r)/2;   //q = 4 
        margeSort(A,p,q);  //0-4
        margeSort(A,q+1,r);  //5-9
        Marge(A,p,q,r);
    }
}

int Marge(int *A, int p, int q, int r){//0 4 9
    int n1 = q - p + 1;//5
    int n2 = r - q;//5
    int L[n1+1];//6
    int R[n2+1];//6
    for(int i = 0; i<n1; i++) L[i] = A[p+i];
    for(int j = 0; j<n2; j++) R[j] = A[q+1+j];
    int i = 0,j = 0;
    L[n1] = 100000;
    R[n2] = 100000;
    for(size_t k = p; k<=r; k++){
        if(L[i]<=R[j]){
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = R[j];
            j++;
        }
    }
}
