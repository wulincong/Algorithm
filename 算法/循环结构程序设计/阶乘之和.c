#include <stdio.h>
#include <time.h>
#define MOD 10000000

int main(int argc, char *argv[]){
    int n,S,Sum;
    scanf("%d",&n);

    for (size_t i = 1; i < n; i++){
        int factor = 1;
        for (size_t j = 1; j <= i; j++){
            factor = factor * j % MOD;
        }
        S = (S+factor) % MOD;
    }
    printf("%d\n",S);
    printf("Time used:%.2f\n",(double)clock() / CLOCKS_PER_SEC);
    return 0;
}
