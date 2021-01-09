#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>


 /*在保证初始代码结构不变的情况下，可以通过下面“char_count”一个函数实现题目的要求，也可以通过多个函数实现*/
    
    /*=============这里往下是你主要编写代码的地方，此区域外的代码都不能删除==================*/

    /*入口函数，不能删除，因为在下方“main”函数中有调用*/
    char* char_count(char* str) {
        char *res;
        char *count;
        char temp[2] = {'\0', '\0'};
        
        int res_pos;
        for (size_t i = 0; str[i] != '\0'; i++)
        {
            size_t j;
            for(j = 1;str[i + j] == str[i];j++){
                //printf("%d", j);
            }
            //printf("%c %d\n",str[i],j);
            temp[0] = str[i];
            res = strcat(res,(char *)temp);
            itoa(j,count,10);
            strcat(res,count);
            if(j == 1)i = i + j;
            else i = i + j - 1;
        }
        
        return res;
    }
    /*其他函数可以从这里写起*/

/*=============这里往上是你主要编写代码的地方，此区域外的代码都不能删除==================*/


int main() {
    char* res;

    char* _str;
    _str = (char *)malloc(512000 * sizeof(char));
    scanf("\n%[^\n]",_str);
    
    res = char_count(_str);
    printf("%s\n", res);
    
    return 0;

}
