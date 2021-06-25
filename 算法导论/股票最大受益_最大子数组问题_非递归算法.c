#include <stdio.h>
#define DATASIZE 17

typedef struct{
    int maxLeft;
    int maxRight;
    int difference;
} Transaction;

Transaction
MAXUMUM_SUBARRAY(int *A,int low,int high);

int main(int argc, char **argv){
    int stockPrice[DATASIZE] = {100,113,110,85,105,102,86,63,81,101,94,106,101,79,94,90,97};
    int Max = -100000,Dif,begin,end;
    int subArray[DATASIZE] = {0};
    Transaction result;
    for(int i = 1; i < DATASIZE;i++) subArray[i] = stockPrice[i] - stockPrice[i-1];
    result = MAXUMUM_SUBARRAY(subArray,1,DATASIZE);
    printf("begin: %d, end: %d\n", result.maxLeft,result.maxRight);
    printf("income: %d \n",result.difference);
}

Transaction
MAXUMUM_SUBARRAY(int *A,int low,int high){
    Transaction result;
    int i = low;
    int maxLeft = i,maxRight = i;
    int sum = A[i];
    int sumH = 0;
    for(int j = low+1;j<= high;j++){
        sumH = 0;
        for(int k = j;k>=i;k--){
            sumH+=A[k];
            if(sumH>sum){
                sum = sumH;
                maxLeft = k;
                maxRight = j;
            }
        }
    }
    result.difference = sum;
    result.maxLeft = maxLeft;
    result.maxRight = maxRight;
    return result;




}