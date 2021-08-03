#include "ADT.h"

void InThread(ThreadTree &p, ThreadTree &pre){
    if(p != NULL){
       InThread(p->lchild, pre);
       if(p->lchild == NULL){
           p->lchild = pre;
           p->ltag = 1;
       } 
       if(pre != NULL && pre->lchild == NULL){
           pre->lchild = p;
           pre->rtag = 1;
       }
       pre = p;  
       InThread(p->rchild, pre);
    }

}

void CreatInThread(ThreadTree T){
    ThreadTree pre = NULL;
    if(T!=NULL){
        InThread(T, pre);
        pre->rchild = NULL;
        pre->rtag = 1;
    }
}

