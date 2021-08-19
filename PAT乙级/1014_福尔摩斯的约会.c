#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]){
    char Str1[61];scanf("%s", Str1);
    char Str2[61];scanf("%s", Str2);
    char Str3[61];scanf("%s", Str3);
    char Str4[61];scanf("%s", Str4);
    char *p,*q,*temp;
    int flag = 0;
    p = Str1;
    q = Str2;
    /*识别出第一个大写字母并打印*/
    while(*p != '\0'){
        if(isupper(*p)){
            while(*q != '\0') {
                if(*p == *q) {flag = 1;break;} 
                else q++;
            }
            if(flag){
                switch(*p){
                    case'A':{printf("MON "); break;}
                    case'B':{printf("TUE "); break;}
                    case'C':{printf("WED "); break;}
                    case'D':{printf("THU "); break;}
                    case'E':{printf("FRI "); break;}
                    case'F':{printf("SAT "); break;}
                    case'G':{printf("SUN "); break;}
                }
            }
            if(!flag) q = Str2;
        }
        if(flag)break;
        p++;
    }//end while1
    
    p++; q++;
    temp = q;
    flag = 0;
    /*识别出第二个大写字母并打印*/
    while(*p != '\0'){
        if(isupper(*p) || isdigit(*p)){  //大写或是数字
            while(*q != '\0') {
                if(*p == *q && *p >= 'A' && *p <= 'N'){
                    printf("%02d:",*p - 'A' + 10);
                    flag = 1;
                    break;
                } 
                else if (*p == *q && isdigit(*p)){
                    printf("0%c:",*p);
                    flag = 1;
                    break;
                }
                else q++;
            }
            q = temp;
        }//end if
        if(flag)break;
        else p++; 
    }//end while2 
    
    for (size_t i = 0; i < 60; i++)
    {
        if(Str3[i] == Str4[i] && isalpha(Str3[i]) ) {
            printf("%02d",i);
            break;
        }
    }
    return 0;

}
// 3485djDkxh4hhGE 
// 2984akDfkkkkggEdsb 
// s&hgsfdk 
// d&Hyscvnm