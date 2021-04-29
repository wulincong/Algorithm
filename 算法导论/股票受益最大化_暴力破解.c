#include <stdio.h>

int main(int argc, char **argv){
    int stockPrice[17] = {100,113,110,85,105,102,86,63,81,101,94,106,101,79,94,90,97};
    int Max = -100000,Dif,begin,end;
    for(int i = 0; i < 17; i++){
        for(int j = i+1; j < 17; j++){
            Dif = stockPrice[j] - stockPrice[i];
            if(Dif > Max) {
                Max = Dif;
                begin = i;
                end = j;
            }
        }
    }
    printf("begin: %d, end: %d\n", begin, end);
    printf("%d\n",Max);
}