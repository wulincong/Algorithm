/*
  input two numbers as a, b,(2 < a < b). Putout the prime number between two numbers.
*/
#include <stdio.h>
#include <stdlib.h>

int isPrime(int n);
int isHuiwen(int);
int main(int argc, char **argv){
    
    int a,b;
    if(argc > 1){
        a = atoi(argv[1]);
        b = atoi(argv[2]);
    }
    else{
        printf("please input two numbers>>>>>");
        scanf("%d %d",&a,&b);
    }

    if(a<3) {
        printf("first number must smaller than 3 ");
        exit(1);
    }
    if(a>b){
        printf("second number must larger than first number ");
        exit(2);
    }
    for(int i = a; i < b; i++){
        if(isPrime(i) && isHuiwen(i)) printf("%d ",i);
        
    }

}


int isPrime(int n){
    for(int i = 2; i * i <= n; i++)if(n % i == 0) return 0;
    return 1;
}

int isHuiwen(int n){
    int t = n, w = 1;
    while(t / 10 != 0) {
        t /= 10;
        w++;
        // printf("w = %d \n",w);
    }
    int ArrayNumber[w+1];
    for(int i = 1; i<=w; i++){
        ArrayNumber[i] = n % 10;
        // printf("Num = %d ",ArrayNumber[i]);
        n = n / 10;
    }
    for(int i = 1; i <= w / 2; i++){
        if(ArrayNumber[i] != ArrayNumber[w+1-i]) return 0;
    }
    return 1;
}