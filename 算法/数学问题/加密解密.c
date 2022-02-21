/*
对字符串进行加密，加密方法：将字符串每个字符加上它在字符串里面的位置和一个偏置量5
比如“mrsoft”，第一个字符'm'-->'m'+0+5 即r
*/

#include <stdio.h>
#include <string.h>
#define BIAS 5
#define MAX_STR 1000

int decode(char*);

int main(int argc,char** argv){
    char str[MAX_STR];
    if(argc > 2){
        if(strcmp(argv[1],"decode")){
            strcat(str,argv[2]);
            puts(str);
        }
        else{
            printf("None");}      
    }
    else{
        printf("<<<");
        fgets(str,MAX_STR,stdin);
    }
    decode(str);
    printf(">>>%s",str);    
}

int decode(char* str){
    char *p = str;  //p指向字符串的某个字符
    int position = 0;  //记录位置
    while(*p != '\0'){
        *p = *p + position + BIAS;
        position++;
        p++;
    }
}

