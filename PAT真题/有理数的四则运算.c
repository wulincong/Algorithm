#include <stdio.h>

int gongYinShu(int A, int B){
    int result = 1;
    for(int i = 2; i <= A; i++){
        if(A % i == 0 && B % i == 0){
            result = i;
        }
    }
    return result;
}

void jiaFenShu(int A, int B){
    int a, b, c; 
    a = A/B;
    b = A - a * B;
    b = b/gongYinShu(A, B);
    c = B/gongYinShu(A, B);
    if(A > B)
        if(b == 0)printf("%d", a);
        else printf("%d %d/%d", a, b, c);
    else printf("%d/%d", b, c);
}

void print(int A, int B){
    // printf("%d %d\n", A, B);
    if(A == 0)printf("0");
    else if(A < 0){
        printf("(-");
        jiaFenShu(-A, B);
        printf(")");
    }
    else if(B < 0){
        printf("(-");
        jiaFenShu(A, -B);
        printf(")");
    }
    else jiaFenShu(A, B);
}

int main(int argc, char **argv){
    int a1, a2, b1, b2;
    scanf("%d/%d %d/%d", &a1, &a2, &b1, &b2);
    int A, B;
    //add 
    {
        A = a1 * b2 + a2 * b1;
        B = a2 * b2;
        print(a1, a2);
        printf(" + ");
        print(b1, b2);
        printf(" = ");
        print(A, B);
        printf("\n");
    }
    //mines
    {
        A = a1 * b2 - a2 * b1;
        B = a2 * b2;
        print(a1, a2);
        printf(" - ");
        print(b1, b2);
        printf(" = ");
        print(A, B);
        printf("\n");
    }
    //cheng
    {
        A = a1 * b1;
        B = a2 * b2;
        print(a1, a2);
        printf(" * ");
        print(b1, b2);
        printf(" = ");
        print(A, B);
        printf("\n");
    }
    //chu 
    {
        A = a1 * b2;
        B = a2 * b1;
        print(a1, a2);
        printf(" * ");
        print(b1, b2);
        printf(" = ");
        if(B == 0) printf("Inf");
        else print(A, B);
        // printf("\n");
    }

}