#include <stdio.h>

int main(int argc, char **argv){
    int Weights[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    char ArrayM[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

    int N, Z, cnt = 0;
    scanf("%d",&N);
    char ID_cards[N][19];
    for(int i=0; i<N; i++){
        scanf("%s",ID_cards[i]);
    }
    for(int i=0; i<N; i++){
        int Weight = 0;
        for(int j=0; j<17; j++)
            Weight += (ID_cards[i][j] - '0') * Weights[j];
        Z = Weight % 11;
        if(ArrayM[Z] != ID_cards[i][17]){
            cnt++;
            printf("%s\n",ID_cards[i]);
        }
    }
    if(cnt == 0)
        printf("All passed");
    return 0;
}