#include "Yutils.h"
#include <math.h>

#define N 10

void test1();
double f1(int n, double a[], double x);
double f2(int n, double a[], double x);
int main(int argc, char **argv){
    double T;
    T = timeIt(test1, 1000000);
    printf("%lf\n", T);

}

void test1(){
    double a[N];
    for (int i = 0; i < N; i++) a[i] = i;
    double x = 2;
    f1(N, a, x);
}


double f1(int n, double a[], double x){
    int i;
    double p = a[0];
    for(i = 1; i < N; i++) p += a[i] * pow(x, i);
    return p;
}
double f2(int n, double a[], double x){
    double p = a[n];
    for( int i = n; i > 0; i--) p = a[i-1] + x * p;
    return p;
}