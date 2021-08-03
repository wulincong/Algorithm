#include <stdio.h>
#include <stdlib.h>

typedef struct TNode {
    int data;
    struct TNode * lchild, *rchild;
} BTree, * BTNode;

BTNode  NewBTNode(int x){
    BTNode node = (BTNode) malloc(sizeof(BTree));
    node->data = x;
    node->lchild = NULL;
    node->rchild = NULL;
}

void insert(BTNode &root, int x){
    /*
    二叉排序树的插入操作，与查询操作类似
    当节点== NULL时，说明不存在该数据，就在这个位置插入即可
    */
    if(root == NULL){
        root = NewBTNode(x);
        return;
    }
    if(root->data == x){
        return ; 
    } else if(x < root->data){
        insert(root->lchild, x);
    } else {
        insert(root->rchild, x);
    }
}

void search(BTNode &root, int x){
    /*
    二叉查找树的查询操作，递归写法
    分为四种情况，如果节点 == NULL 查找失败
    节点->data == x 查找成功
    节点->data < x 向右查找
    节点->data > x 向左查找
    */
    if(root == NULL){
        printf("search failed\n");
        return;
    }
    if(root->data == x){
        printf("%d\n", root->data);
        return ; 
    } else if(x < root->data){
        search(root->lchild, x);
    } else {
        search(root->rchild, x);
    }
}

BTNode Create(int data[], int n){
    BTNode root = NULL;
    for(int i = 0; i < n; i++){
        insert(root, data[i]);
    }
    return root;
}

BTNode findlMax(BTNode &root){
    while(root->rchild != NULL){
        root = root->rchild;
    }
    return root;
}

BTNode findrMin(BTNode &root){
    while(root->lchild != NULL){
        root = root->lchild;
    }
    return root;
}

void deleteBTNode(BTNode &root, int x){
    /*
    删除某个节点
    如果树是空树，则直接返回
    如果当前节点是要删除的节点，找到节点的前驱或后继，将前驱或后继代替当前节点
    如果x > 当前节点 向右递归
    如果x < 当前节点 向左递归
    */
    if(root == NULL) return;
    if(root->data == x){ // 找到了要删除的节点
        //如果这个节点没有左右孩子
        if(root->lchild == NULL && root->rchild == NULL) {
            root == NULL;
        } else if(root->lchild != NULL){//左孩子不空
            BTNode pre = findlMax(root->lchild);
            root->data = pre->data;
            deleteBTNode(root->lchild, pre->data);
        }else{
            BTNode next = findlMax(root->rchild);
            root->data = next->data;
            deleteBTNode(root->rchild, next->data);
        }
   }
   else if(root->data > x){ 
       deleteBTNode(root->lchild, x);
   }else{
       deleteBTNode(root->rchild, x);
   }
}