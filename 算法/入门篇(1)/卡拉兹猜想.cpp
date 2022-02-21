#include <stdio.h>
int main(int argc, char *argv[]){
    int i = 0;
    int n;
    printf(">>>");
    scanf("%d", &n);
    while(n != 1){
        i++;
        if(n % 2 == 0){
            n = n / 2;
        }
        else{
            n = (3 * n + 1) / 2;
        }
    }
    printf("%d\n", i);
    return 0;
}