#include <cstdio>

#include <iostream>

using namespace std;

typedef struct node {
    int v, height;
    struct node *lchild, *rchild;
} AVLTree, * AVLNode;

AVLNode newNode(int v){
    AVLNode node = (AVLNode) malloc(sizeof(AVLTree));
    node->v = v;
    node->height = 1;
    node->lchild = node->rchild = NULL;
    return node;
}

int getHeight(AVLNode root){
    if(root == NULL) return 0;
    return root->height;
}

int getBanlanceFavtor(AVLNode root){
    return getHeight(root->lchild) - getHeight(root->rchild);
}

void updateHeight(AVLNode root){
    root->height = max(getHeight(root->lchild),getHeight(root->rchild)) + 1;
}

void L(AVLNode root){
    //左旋调整
    AVLNode temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root; 
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void R(AVLNode root){
    //右旋调整
    AVLNode temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}
