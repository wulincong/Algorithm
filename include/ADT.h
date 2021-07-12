#ifndef ElemType
#define ElemType int
#endif

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
