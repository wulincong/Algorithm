#include <stdio.h>

int main(int argc, char **argv){
    int A, B, D, i = 0;
    scanf("%d %d %d",&A,&B,&D);
    int res = A + B;
    char buf[50];
    
    while(res > 0){
        buf[i] = res % D;
        res = res / D; i++;
    }
    i = i - 1;
    for( ; i >= 0; i--)printf("%d",buf[i]);
    
}