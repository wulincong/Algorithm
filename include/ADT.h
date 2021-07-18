#ifndef ElemType
#define ElemType int
#include <stdio.h>

typedef struct{
    ElemType *data;
    int MaxSize;
    int length;
} SqeList;

// L.data = (ElemType*) malloc(sizeof (ElemType) * InitSize);

typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;
// (LNode*)malloc(sizeof(LNode));

#define MAXSIZE 50 

typedef struct {
    ElemType data[MAXSIZE];
    int top;
} SqStack;

typedef struct SLinknode{
    ElemType data;
    struct SLinknode *next;
} *LiStack;

typedef struct {
    ElemType data[MAXSIZE];
    int front;      //队头指针
    int rear;       //队尾指针
} SqQueue;

typedef struct BiTNode{
    ElemType data; 
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

extern void visit(BiTree);

void PreOrder(BiTree T){
    if(T != NULL){
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

void InOrder(BiTree T){
    if(T != NULL){
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}


void PostOrder(BiTree T){
    if(T != NULL){
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
}



#endif