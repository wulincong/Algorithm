#include <stdio.h>

int main(int argc, char *argv[]){
    int A,D_A, B,D_B;
    scanf("%d %d %d %d", &A, &D_A, &B, &D_B);
    int num_D_A = 0, num_D_B = 0;
    int tmp = 1;
    while (A > 0)
    {
        if(A % 10 == D_A){
            num_D_A += D_A *tmp ;
            tmp *= 10;
        };
        A = A / 10;
    }
    tmp = 1;
    while(B > 0){
        if(B % 10 == D_B){
            num_D_B += D_B *tmp;
            tmp *= 10;
        }
        B = B / 10;
    }
    printf("%d\n",num_D_A+num_D_B);
    return 0;
    
}