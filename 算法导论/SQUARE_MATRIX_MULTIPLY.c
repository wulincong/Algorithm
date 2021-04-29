#include <stdio.h>
#define N 2 

void * SQUARE_MATRIX_MULTIPLY(int A[N][N], int B[N][N], int n);

int main(int argc, char **argv){
    int A[N][N] = {{1,2},{3,4}};
    int B[N][N] = {{4,3},{2,1}};
    int (*C)[N] = SQUARE_MATRIX_MULTIPLY(A, B, N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("%d ",C[i][j]);
        }
        printf("\n");
    }
}

void * SQUARE_MATRIX_MULTIPLY(int A[N][N], int B[N][N], int n){
    static int C[N][N];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            C[i][j] = 0;
            for(int k = 0; k < n; k++){
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
            // printf("%d ", C[i][j]);
        }
        // printf("\n");
    }
    return C;
}

