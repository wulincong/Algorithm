#include <stdio.h>
#include <ctype.h>

#define N 61
// 3485djDkxh4hhGE 
// 2984akDfkkkkggEdsb 

//在第一个字符串找到两对相同的大写字母，
//在第二个字符串找到一对相同的小写字母

int main(int ac, char **av){
    char str1[N]; scanf("%s", str1);
    char str2[N]; scanf("%s", str2);
    char str3[N]; scanf("%s", str3);
    char str4[N]; scanf("%s", str4);
    int flag = 0;
    for(int i = 0; i < N; i++){
        if(str1[i] == '\0' || str2[i] == '\0' ||flag >= 2) break;
        if(str1[i] == str2[i]){
            if(flag == 0  && isupper(str1[i])){  //找第一个相同字母
                switch(str1[i]){
                    case 'A' :{printf("MON "); flag++; break;}
                    case 'B' :{printf("TUE "); flag++; break;}
                    case 'C' :{printf("WED "); flag++; break;}
                    case 'D' :{printf("THU "); flag++; break;}
                    case 'E' :{printf("FRI "); flag++; break;}
                    case 'F' :{printf("SAT "); flag++; break;}
                    case 'G' :{printf("SUN "); flag++; break;}
                }
            }else if(flag == 1){  //找第二个相同字母
                if(str1[i] >= '0' && str1[i] <= '9'){
                    printf("0%c:", str1[i]);
                    flag++;
                }
                else if(str1[i] >= 'A' && str1[i] <= 'N'){
                    printf("%02d:", str1[i] - 'A' + 10);
                    flag++;
                }
            }
        }
    }

// s&hgsfdk 
// d&Hyscvnm
    for(int i = 0; i < N; i++){
        if(str3[i] == '\0' || str4[i] == '\0' || flag >= 3) break;
        if(str3[i] == str4[i] && isalpha(str3[i])){
            printf("%02d", i);
            flag++;
        }
    }
}
