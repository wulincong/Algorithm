
int compare_and_swap(int *word, int testval, int newval){
    int oldval;
    oldval = *word;
    if(oldval == testval)*word = newval;
    /* 用testval值检查内存值，如果和预测值相等，则把内存值替换成新值*/
    return oldval;
}

void exchange(int *reg, int *memory){
    /*交换了内存和某个寄存器的值*/
    int tmp;
    tmp = *memory;
    *memory = *reg;
    *reg = tmp;
}

const int n = 10; //进程个数
int bolt;
void P(int i){
    while(1){
        while(compare_and_swap(bolt, 0, 1) == 1);//检查bolt是否为0，如果是0则是本进程获得使用权
        /*临界区*/;
        bolt = 0; //释放资源
        /*剩余区*/
    }
}

void P_e(int i){
    while(1){
        int keyi = 1;
        do exchange(keyi, bolt);
        while (keyi != 0);
        /*临界区*/
        bolt = 0;
        /*剩余区*/
    }
}

