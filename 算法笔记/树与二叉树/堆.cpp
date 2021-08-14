#include <iostream>

const int maxn = 100; //
int heap[maxn], n = 10; //

void downAdjust(int low, int high){
    //low是欲调整节点的下标，high是最后一个元素的数组下标
    int i = low, j = i * 2;  // i是根节点， j是左孩子下标
    while(j <= high){  // 如果存在左孩子
        if(j + 1 <= high && heap[j + 1] > heap[j]){  // 右孩子大于左孩子
            j = j + 1;  //j存储最大孩子的下标
        }
        if(heap[j] > heap[i]){ //孩子中的大者大于根
            int tmp = heap[i];
            heap[i] = heap[j];
            heap[j] = tmp;
            i = j;
            j = i * 2; 
        }else break; //孩子的最大者小于根节点
    }
}

void creatHeap(){
    for(int i = n / 2; i >= 1; i-- ){
        downAdjust(i, n);
    }
}

void deleteTop(){
    heap[1] = heap[n--];  //让根节点等于最后一个节点，并且元素的个数-1
    downAdjust(1, n);
}

void upAdjust(int low , int high){ 
    int current = high, father = current / 2;   //父节点
    while(father >= low){   //父节点不超过low
        if(heap[father] < heap[current]){  //父节点小于当前节点，说明需要调整
            int tmp = heap[father];
            heap[father] = heap[current];
            heap[current] = tmp;
            current = father;
            father = current / 2; //
        }else break; //
    }
}

void insert(int x){
    heap[++n] = x; //
    upAdjust(1, n);
}
