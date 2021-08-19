#include <bits/stdc++.h>

using namespace std;
#define MAX 1000

typedef struct {
    int *items;
    int size;
    int head, tail;
} Queue;



void BFS(int u){
    bool inq[MAX] = {false};
    Queue q;
    q.items = (int *)malloc(sizeof(int) * MAX);
    q.size = MAX;
    q.head = 0;
    q.tail = 0;
    q.items[q.tail++] = u;
    inq[u] = true;
    while(q.head != q.tail){
        //  for i in u的邻居，将他们入队
        //      if(inq[u] == false):      
        //          inq[i] = true
    }
}

void BFSTrave(int *G){
    for(int i = 0; i < MAX; i++){
        BFS(i);
    }
}

