#include <stdio.h>

char * longestCommonPrefix(char ** strs, int strsSize){
    static char prefix[200];
    char current_char;
    int flag = 1;
    int i;
    for(i = 0; i < 200; i++){   //first char
        current_char = strs[0][i];
        flag = 1;
        for(int j = 0; j < strsSize; j++){   //遍历列表
            if(strs[j][i] == current_char)continue;
            else {
                flag = 0;
                break;
            };
        }
        if(!flag)break;
        else{
            prefix[i] = current_char;
        }
    }
    prefix[i] = '\0';
    return prefix;
}

int main(int argc, char ** argv){
    char *strs[] = {"flower","flow","flight"};
    char *result = longestCommonPrefix(strs,3);
    printf("result:%s",result);
}

