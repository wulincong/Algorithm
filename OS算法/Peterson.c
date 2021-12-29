#define FALSE 0
#define TRUE 1
#define N 2         //进程数量

int turn;           //现在轮到谁？
int interested[N];  //所有的值初始化为0
void enter_region(int process){ // 1 or 0 ?
    int other;                  
    other  = 1 - process;       //另一个进程号
    interested[process] = TRUE; //表示感兴趣    
    turn = process;             //设置标志
    while (turn == process && interested[other] == TRUE); //上一步执行
}

void leave_region(int process){
    interested[process] = FALSE;
}