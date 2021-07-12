#include <stdio.h>

int main(int argc, char **argv){
    int N;
    float Sum = 0.0;
    scanf("%d",&N);
    float Array[N];
    for(int i=0; i<N; i++){
        scanf("%e",&Array[i]);
    }

    for(int i=0; i<N; i++){
        for(int j = i; j < N; j++){
            Sum += Array[j] * (N - j);
        }
    }
    //Sum = ((int)(Sum * 1000.0 + 5)) / 1000.0;
    printf("%.2f\n", Sum);
}