#include <stdio.h>

int main(int argc, char **argv){
    int N, t_n, t_s;
    scanf("%d",&N);
    int school[100000];
    for(int i = 0; i < N ; i++)school[i] = 0;
    for(int i = 0; i < N ; i++){
        scanf("%d %d",&t_n, &t_s);
        school[t_n] += t_s;
        
    }
    int maxNumber = 0;
    for(int i = 1; i <= N ; i++){
        if(school[i] > school[maxNumber]) maxNumber = i;
    }
    printf("%d %d",maxNumber, school[maxNumber]);
    return 0;
}