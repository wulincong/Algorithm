#include <stdio.h>

#define N 4
int Stay[N];
int A[N] = {0,1,2,3,};

void PowerSet(int i, int n){
    // 求幂级 i 是当前层次，如果i > n,输出
    // 否则分两种情况，一种是取，一种是舍
    if(i > n){
        for(int j = 0; j < n; j++) {
            if(Stay[j] == 1)
                printf(" %d", A[j]);
            else printf(" *");
        }
        printf("\n");
    }
    else{
        //不取情况
        Stay[i] = 0;
        PowerSet(i+1, n);
        //取的情况
        Stay[i] = 1;
        PowerSet(i+1, n);
    }
}

int main(){
    int n = N;
    PowerSet(0, n);
}


