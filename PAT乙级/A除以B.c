#include <stdio.h>

int main(int argc, char **argv){
    char N[1000];
    int8_t Yushu = 0;
    int8_t Chushu;
    scanf("%s %hhd", N, &Chushu);
    char *p = N;
    int cnt = 0; //位数
    while(*p != '\0'){
        *p = *p - '0';
        cnt++;
        p++;
    }
    for(int i = 0; i < cnt; i++){
        int8_t y = Yushu;
        Yushu = (Yushu * 10 + N[i]) % Chushu;
        N[i] = (y * 10 + N[i]) / Chushu + '0';
    }
    p = N;
    printf("%s", *p == '0' ? ++p : p);
    printf(" %hhd\n", Yushu);

}