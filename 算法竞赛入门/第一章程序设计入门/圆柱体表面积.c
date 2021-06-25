#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]){
    const double pi = acos(-1);
    double r,h,s_buttom,s_side;
    scanf("%lf%lf",&r,&h);
    s_buttom = 2*pi*r*r;
    s_side = 2*pi*r*h;
    printf("Area = %.3lf\n",s_buttom+s_side);
    return 0;
}