/*信号量原语*/
#define queueType int*

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

typedef struct semaphore{
    int count;
    int flag;
    queueType queue;
} semaphore;

void semWait(semaphore s){
    while(compare_and_swap(s.flag, 0, 1) == 1);
    s.count--;
    if(s.count < 0){
        /*把当前进程入queue*/
        /*阻塞当前进程*/
    }
    s.flag = 0;
}

void semSignal(semaphore s){
    while(compare_and_swap(s.flag, 0, 1) == 1);
    s.count++;
    if(s.count<=0){
        /*从队列中取一个进程P*/
        /*进程P加入就绪队列*/
    }
    s.flag = 0;
}

/*使用信号量互斥的例子*/


semaphore s = {1};

void P(int i){
    while(1){
        semWait(s);
        /*临界区*/
        semSignal(s);
        /*剩余区*/
    }
}

//生产者消费者问题

semaphore s = {1}; //互斥访问缓冲区
semaphore n = {0}; //当前产品数量

void producer(){
    while(1){
        //produce()
        semWait(s);//获取权限
        //append()
        semSignal(s);
        semSignal(n);
    }
}

void consumer(){
    while(1){
        semWait(s);
        semWait(n);
        //take()
        semSignal(s);
        //consume();
    }
}

