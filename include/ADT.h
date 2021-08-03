#ifndef ADT_H
#define ADT_H

#ifndef ElemType
#define ElemType int
#endif

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


typedef struct ThreadNode{
    ElemType data;
    struct ThreadNode *lchild, *rchild; //左、右孩子指针
    int ltag, rtag;                     //左、右孩子标志
} ThreadNode, *ThreadTree;


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

#define MaxVertexNum 100

#ifndef VertexType 
#define VertexType char
#endif

#ifndef EdgeType
#define EdgeType int
#endif

typedef struct{
    VertexType Vex[MaxVertexNum];
    EdgeType Edge[MaxVertexNum][MaxVertexNum];
    int vexnum, arcnum;
}MGraph;

typedef struct ArcNode{
    int adjvex;
    struct ArcNode *next;   
} ArcNode;

typedef struct VNode{
    VertexType data;
    ArcNode *first;
} VNode, AdjList[MaxVertexNum];

typedef struct {
    AdjList vertices;
    int vexnum, arcnum;
}ALGraph;



#endif