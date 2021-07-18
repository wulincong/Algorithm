#include <stdio.h>

#define FALSE 0
#define TRUE 1

int isPrime(int x) {
    if(x < 2) return FALSE;
    if(x == 2) return TRUE;
    int i = 2;
    while(i * i <= x) {
        if(x % i == 0) return FALSE;
        i++;
    }
    return TRUE;
}

int main(int argc, char **argv) {
    int N;
    if(argc < 2) {
        scanf("%d", &N);
    }
    else{
        N = atoi(argv[1]);
    }
    int cnt = 0;
    for(int i = 5; i <= N; i++){
        if(isPrime(i) & isPrime(i - 2)) {
            // printf("%d, %d isPrime\n", i, i + 2);
            cnt++;}
    }
    printf("%d\n", cnt);
}