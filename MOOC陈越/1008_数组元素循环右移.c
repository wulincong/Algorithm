#include <stdio.h>

int main(int argc, char **argv){
    int N, shr;
    scanf("%d %d",&N,&shr);
    int A[N];
    shr = shr % N;
    for(int i = 0; i < N; i++) scanf("%d",&A[i]);
    for(int i = N - shr; i < N; i++) printf("%d ",A[i]);
    for(int i = 0; i < N - shr; i++){
        printf("%d",A[i]);
        if (i != N - shr - 1) printf(" ");
    } 

}