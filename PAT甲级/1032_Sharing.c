#include <stdio.h>

int main(){
    int B1, B2, N;
    scanf("%d %d %d",&B1,&B2,&N);
    int Address[100000];
    char Chars[100000];
    for(int i = 0; i < N; i++){
        int addr, next;
        char c;
        scanf("%d %c %d",&addr,&c,&next);
        Address[addr] = next;
        Chars[addr] = c;
    }
    int len1 = 1, len2 = 1;
    int *p1 = &Address[B1];
    int *p2 = &Address[B2];
    while(*p1 != -1){len1++; p1 = &Address[*p1];}
    while(*p2 != -1){len2++; p2 = &Address[*p2];}
    // printf("%d %d", len1, len2);

    p1 = &Address[B1]; p2 = &Address[B2];
    int *P_l, *P_s;  //短单词和长单词
    if(len1 > len2){
        P_l = p1, P_s = p2;
    } else{
        P_s = p1, P_l = p2;
    }
    int l = len1 > len2 ? len1 - len2 : len2 - len1;
    // printf(" %d ", l);
    for(int i = 0; i < l; i++){
        P_l = &Address[*P_l];
        // printf(" %d ", *P_l);
    }
    while(*P_l != *P_s){
        P_l = &Address[*P_l];
        P_s = &Address[*P_s];
    }
    printf("%d\n",*P_l);
}   

