#include <stdio.h>
#include <math.h>

int main(int argc, char **argv){
    float C1, C2;
    int H, M, S, T;
    
    scanf("%e %e",&C1,&C2);
    T = round((C2 - C1) / 100);
    S = T % 60;
    T /= 60;
    M = T % 60;
    T /= 60;
    H = T % 60;
    printf("%02d:%02d:%02d", H, M, S);
    return 0;
}
