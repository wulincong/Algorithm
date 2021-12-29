
typedef struct BiTreeNode{
    int e;
    struct BiTreeNode * lchild;
    struct BiTreeNode * rchild;
}*BiTree, *BiTreeNode;

void InOrder_Stack(BiTree T){
    BiTreeNode Stack[100];
    int top = 0;
    BiTreeNode p = T;
    while(p || top != 0){
        if(p){ //当前节点非空，则左孩子入栈
            Stack[top++] = p;
            p = p->lchild;
        }else{ //如果当前节点是空节点，则需要出栈获得上一个节点
            p = Stack[--top];
            p = p->rchild;
        }
    }
}

void preOrder(BiTree T){
    if(T){
        printf("%d", T->e);
        preOrder(T->lchild);
        preOrder(T->rchild);
    }
}

void inOrder(BiTree T){
    if(T){
        inOrder(T->lchild);
        printf("%d",T->e);
        inOrder(T->rchild);
    }
}

void postOrder(BiTree T){
    if(T){
        postOrder(T->lchild);
        postOrder(T->rchild);
        printf("%d", T->e);
    }
}

