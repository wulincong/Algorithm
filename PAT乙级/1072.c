#include <stdio.h>

int main(int argc, char **argv){
    int N, M, w, n, cnt_s = 0, cnt_w = 0;
    
    char name[100];
    int W[10000];
    int SW[100];
    int SW_f[100];
    for(int i=0; i<10000; i++) W[i] = 0;
    scanf("%d %d", &N, &M);
    for (int i=0; i<M; i++){
        scanf("%d", &w);
        W[w] = 1;
    }

    for(int i = 0; i < N; i++){
        for(int i=0; i<100; i++) SW_f[i] = 0;
        int flag = 0;
        scanf("%s %d", name, &n);
        for (int j = 0; j < n; j++){
            scanf("%d", &SW[j]);
            if(W[SW[j]] == 1){
                cnt_w ++;
                SW_f[j] = 1;
                flag = 1;
            }
        }
        if(flag == 1){
            cnt_s ++;
            printf("%s:", name);
            for(int j = 0; j < n; j++){
                // printf("%d ", SW_f[j]);
                // printf("%d ", W[SW[j]]);
                if(SW_f[j]){
                    printf(" %d", SW[j]);
                }
            }
            printf("\n");
        }
    }
    printf("%d %d", cnt_s, cnt_w);
}