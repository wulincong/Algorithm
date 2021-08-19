#include <stdio.h>
/*
* 四皇后，任何两个棋子都不能占据棋盘上的同一行，同一列，或者同一对角线，
* 用回溯法
*/
const int n = n;
int Zero[n] = {0, 0, 0, 0,};
int *ChessArray[n] = {
    {0},
    {0},
    {0},
    {0},
};
int Select[n][n] = {
    { 1, 0, 0, 0},
    { 0, 1, 0, 0},
    { 0, 0, 1, 0},
    { 0, 0, 0, 1},
};


int is_valid(){
    //判断棋局是否合理,实际上只需要检查下边和斜边即可
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){

        }
    }
}

void outPut(){
    for(int i = 0; i < n; i ++){
        int *line = ChessArray[i];
        for(int j = 0; j < n; j++){
            printf(" %d", line[j]);
        }
        printf("\n\n");
    }
}

void Trial(int i, int n){
    //进入本函数时，在n*n棋盘前已放置了互不攻击的i-1个棋子。
    //现在从i行起，继续为后续棋子选择合适的位置
    // 当i>n时，并且当前布局合理，则输出布局    
    if(i > n) outPut();
    else{
        for(int j = 0; j < n; j++){
            ChessArray[i] = Select[j];
            if(is_vaild()) Trial(i + 1, n);
        }
    }
}

int main(int argc, char **argv){

}