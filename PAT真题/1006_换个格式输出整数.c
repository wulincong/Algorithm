#include <stdio.h>

int main(int argc, char **argv){
    int n;
    if (argc < 2){
        scanf("%d",&n);
    }
    else{
        n = atoi(argv[1]);
    }
    int B_num, S_num, G_num;
    G_num = n % 10;
    n = n / 10;
    S_num = n % 10;
    n = n / 10;
    B_num = n % 10;
    for(int i = 0; i < B_num; i++) printf("B");
    for(int i = 0; i < S_num; i++) printf("S");
    for(int i = 1; i <= G_num; i++) printf("%d",i);
}