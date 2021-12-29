#include <stdio.h>

int main(int argc, char **argv){
    int T, K;
    int n1, b, t, n2;
    scanf("%d %d", &T, &K);
    while(T > 0 && K > 0){
        scanf("%d %d %d %d", &n1, &b, &t, &n2);
        int res = n1 < n2;
        if(t > T){
            printf("Not enough tokens.  Total = %d.\n", T);
            continue;
        }
        if(res == b){//玩家赢
            T += t;
            printf("Win %d!  Total = %d.\n",t, T);
        }else{ //玩家输
            T -= t;
            printf("Lose %d.  Total = %d.\n", t, T);
        }
        if(T <= 0){
            printf("Game Over.\n");
            break;
        }
        K--;
    }
}