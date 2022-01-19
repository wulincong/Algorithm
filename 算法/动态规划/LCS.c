#include <stdio.h>
#define LEFTUP 0 
#define UP 1 
#define LEFT 2

void print_table(void *A, int m, int n);
void LCS_length(char *X, int length_X, char *Y, int length_Y);

int main(int argc, char **argv){
    char *X = "ABCBDAB";
    char *Y = "BDCABA";
    LCS_length(X,7,Y,6);
}

void LCS_length(char *X, int length_X, char *Y, int length_Y){
    int m = length_X;
    int n = length_Y;
    int b[m][n];   // b is leftup | up | left
    int c[m][n];    // c is c[i,j]
    for(size_t i = 1; i < m; i++)c[i][0] = 0;
    for(size_t j = 0; j < n; j++)c[0][j] = 0;
    printf("OK");
    for(size_t i = 1; i < m; i++){
        for(size_t j = 1; j < n; j++){
            if(X[i] == Y[j]){
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = LEFTUP;
            }
            else if(c[i-1][j] >= c[i][j-1]){
                c[i][j] = c[i-1][j];
                b[i][j] = UP;
            }
            else {
                c[i][j] = c[i][j-1];
                b[i][j] = LEFT;
            }
        }
    }
    for(size_t i = 0; i < m; i++) {
        for(size_t j = 0; j < n; j++)
            printf("%d\t",b[i][j]);
        printf("\n");
    }
    for(size_t i = 0; i < m; i++) {
        for(size_t j = 0; j < n; j++)
            printf("%d\t",c[i][j]);
        printf("\n");
    }

}

void print_table(void *A, int m, int n){
    for(size_t i = 0; i < m; i++) 
        for(size_t j = 0; j < n; j++)
            printf("%d ",((int **)A)[i][j]);
}