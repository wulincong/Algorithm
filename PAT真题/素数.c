#include <stdio.h>
#include <math.h>
int main(){
    int maxNumber;
    int M, p = 1, N ,j;
    scanf("%d %d",&M,&N);
    if(N*N < 100000)
        maxNumber = N * N;
    else maxNumber = 100000;
    int Arr[maxNumber + 1];
    int ArraySuList[maxNumber];
    j = maxNumber;
    while (j--){Arr[j] = 1;}
    int i = 1;
    while (i < sqrt(maxNumber))
    {
        if(Arr[++i] == 0) ;
        else{
            for (size_t j = 2; i * j < maxNumber; j++)
            {
                Arr[i * j] = 0;
            }
        }
    }
    j = 2;
    while (j<maxNumber+1){
        if(Arr[j] == 1)
            //printf("%d,",N);
            ArraySuList[p++] = j;
        j++;
    }
    
    int num = 1;
    while(M<N){
        if(num%10 != 0){
            printf("%d ",ArraySuList[M]);
            num++;
        }else{
            printf("%d\n",ArraySuList[M]);
            num = 1;
        }
        M++;
    }
    printf("%d",ArraySuList[N]);
    return 0;
}
