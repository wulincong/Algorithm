#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>


/*在保证初始代码结构不变的情况下，可以通过下面“arraySort”一个函数实现题目的要求，也可以通过多个函数实现*/
    
/*=============这里往下是你主要编写代码的地方，此区域外的代码都不能删除==================*/

/*入口函数，不能删除，因为在下方有调用*/
int* arraySort(int arr_size, int* arr,int* result_size) {
    int min_size;
    for(int i = 0; i < arr_size; i++) {
        min_size = i;
        for(int j = i; j < arr_size; j++){
            if(arr[j] < arr[min_size]){
                min_size = j;
            }
        }
        int tem = arr[min_size];
        arr[i] = arr[min_size];
        arr[min_size] = tem;
        result_size[i] = tem;
    }

}
/*其他函数可以从这里写起*/

/*=============这里往上是你主要编写代码的地方，此区域外的代码都不能删除==================*/



int main() {
    int res_size;
    int* res;

    int _arr_size = 0;
    int _arr_i;
    scanf("%d\n", &_arr_size);
    int _arr[_arr_size];
    for(_arr_i = 0; _arr_i < _arr_size; _arr_i++) {
        int _arr_item;
        scanf("%d", &_arr_item);
        
        _arr[_arr_i] = _arr_item;
    }   
 
    res = arraySort(_arr_size, _arr, &res_size);
    for(size_t res_i=0; res_i < res_size; res_i++) {
    
        printf("%d\n", res[res_i]);
        
    }
    
    return 0;

}
