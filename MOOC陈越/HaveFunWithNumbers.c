#include <stdio.h>

int main(int argc, char **argv){
    unsigned long N, M, t;
    int flag = 1;
    scanf("%ld", &N);
    M = N * 2;
    int A[10] = {0};
    t = N;
    while(t  > 0){
        A[t % 10] = 1;
        t /= 10;
    }
    t = M;
    while(t > 0){
        if(A[t % 10] == 1) A[t % 10] = 3;
        else if(A[t % 10] == 3) continue;
        else if(A[t % 10] == 0){
            flag = 0;
            break;
        }
        t /= 10;
    }
    for (int i = 0; i < 10; i++) {
        if(A[i] == 1){
            flag = 0;
            break;
        }
    }
    if(flag) printf("Yes\n");
    else printf("No\n");
    printf("%ld\n", M);
}