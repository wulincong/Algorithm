#include <stdio.h>
#define DATASIZE 17

typedef struct{
    int maxLeft;
    int maxRight;
    int difference;
} Transaction;

Transaction 
FIND_MAX_CROSSING_SUBARRAY(int *A, int low, int mid, int high);
Transaction 
FIND_MAXIMUM_SUBARRAY(int *A, int low, int high);

int main(int argc, char **argv){
    int stockPrice[DATASIZE] = {100,113,110,85,105,102,86,63,81,101,94,106,101,79,94,90,97};
    int Max = -100000,Dif,begin,end;
    int subArray[DATASIZE] = {0};
    Transaction result;
    for(int i = 1; i < DATASIZE;i++) subArray[i] = stockPrice[i] - stockPrice[i-1];
    result = FIND_MAXIMUM_SUBARRAY(subArray,1,DATASIZE);
    printf("begin: %d, end: %d\n", result.maxLeft,result.maxRight);
    printf("income: %d \n",result.difference);
}

Transaction 
FIND_MAX_CROSSING_SUBARRAY(int *A, int low, int mid, int high){
    Transaction result;
    int leftSum = -1000000;
    int sum = 0;
    for(int i = mid;i >= low ; i--){
        sum = sum + A[i];
        if(sum > leftSum){
            leftSum = sum;
            result.maxLeft = i;
        }
    }
    int rightSum = -10000000;
    sum = 0;
    for(int i = mid+1; i<= high; i++){
        sum+=A[i];
        if(sum > rightSum){
            rightSum = sum;
            result.maxRight = i;
        }
    }
    result.difference = leftSum + rightSum;
    return result;

}

Transaction 
FIND_MAXIMUM_SUBARRAY(int *A, int low, int high){
    Transaction result;
    if(high==low){
        result.maxLeft = low;
        result.maxRight = high;
        result.difference = A[low];
        return result;
    }
    else{
        int mid = (low+high)/2;
        Transaction resultLow = FIND_MAXIMUM_SUBARRAY(A,low,mid);
        Transaction resultHigh = FIND_MAXIMUM_SUBARRAY(A,mid+1,high);
        Transaction resultMid = FIND_MAX_CROSSING_SUBARRAY(A,low,mid,high);
        if(resultLow.difference >= resultHigh.difference && resultLow.difference >= resultMid.difference)
            return resultLow;
        else if(resultMid.difference >= resultHigh.difference && resultMid.difference >= resultLow.difference)
            return resultMid;
        else return resultHigh;
    }

}
