int count = 0;
semaphore mutex = {1}; //保护count的互斥访问
semaphore rw = {1}; //读写者排他的互斥访问

void writer(){
    while (1){
        P(rw);
        writing();
        V(rw);
    }
}

void reader(){
    while(1){
        P(mutex);
        if(count == 0)P(rw);
        count++;
        V(mutex);
        reading();
        P(mutex);
        count--;
        if(count == 0) V(rw);
        V(mutex);
    }
}

