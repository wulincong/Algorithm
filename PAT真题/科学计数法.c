#include <stdio.h>

int main(int argc, char **argv){
    //N = a * 10 ^ b
    char F_a, F_b;
    char a[9999];
    int len_a = 0, len_b = 0, i = 0;
    int b;
    scanf("%c",&F_a);
    if(F_a == '+'){}
    else printf("-");
    while(scanf("%c", &a[i]) != EOF){
        if(a[i] == '.') continue;
        if(a[i] == 'E') {
            len_a = i;
            break;
        }
        else {
            i++;
        }
    };
    scanf("%d", &b);
    if(b >= 0){
        for(int i = 0; i < len_a; i++){
            printf("%c",a[i]);
            if(i == b) printf(".");
        }
        if(len_a < b){
            for(int i = 0; i < b - len_a + 1; i++)printf("0");
        }
    }
    if(b < 0){
        printf("0.");
        for(; b < -1; b++)printf("0");
        for(int i = 0; i < len_a; i++) printf("%c",a[i]);
    }
}