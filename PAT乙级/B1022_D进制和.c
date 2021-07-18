#include <stdio.h>

int main(int argc, char *argv[]){
    int a,b,d,sum;
    int stack[60],*p,*q;
    p = stack;
    scanf("%d %d %d",&a,&b,&d);
    sum = a + b;
    while (sum != 0)
    {
        *p++ = sum % d;
        sum /= d;
    }
    q = stack;
    while (q != p)
    {
        printf("%d",*--p);
    }
    return 0;
}