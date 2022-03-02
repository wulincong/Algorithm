#include <cstdio>

#include <iostream>

using namespace std;

typedef struct node {
    int v, height;
    int data;
    struct node *lchild, *rchild;
} AVLTree, * AVLNode;

AVLNode newNode(int v){
    AVLNode node = new AVLTree;
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

AVLNode search(AVLNode root, int x){
    /*
    查找操作，与普通二叉查找树相同
    */
   if(root == NULL){
       printf("search failed\n");
       return NULL;
   }
   if(root->data == x){
       return root;
   }else if(root->data > x){
       return search(root->lchild, x);
   }else{
       return search(root->rchild, x);
   }
}

void insert(AVLNode root, int x){
    /*
    平衡二叉树的插入操作
    如果当前节点为空节点，插入之，
    如果当前节点不是空的，则需要根据是否失衡进行调整，
    */
    if(root == NULL){
        root = newNode(x);
        return;
    }
    if(root->data == x) return;
    if(root->data > x){
        insert(root->lchild, x);
        //之后调整
        updateHeight(root);     //更新树高
        if(getBanlanceFavtor(root) == 2){ // 如果BF = 2
            if(getBanlanceFavtor(root->lchild) == 1) R(root);  //需要右旋
            /*
                    1*                2*              
                  2*       ---->    3*   1*           
                3*                                    
            */
            else if(getBanlanceFavtor(root->lchild) == -1){  // 
            /*
                    1*                1*             3*
                  2*       ---->    3*     ---->   2*   1*
                    3*            2*                       
            */
                L(root->lchild);
                R(root);
            }
        }
    }else {
        insert(root->rchild, x);
        updateHeight(root);
        if(getBanlanceFavtor(root) == -2){ // BF = -2
            if(getBanlanceFavtor(root->rchild) == -1) L(root);   //需要左旋
            /*
                1*                     2*              
                   2*       ---->    1*   3*           
                      3*                                    
            */
            if(getBanlanceFavtor(root->rchild) == 1){
            /*
                1*                1*                 3*
                   2*    ---->       3*     ---->  1*   2*      
                  3*                    2*           
            */
                R(root->rchild);
                L(root);
            }    
        }
    }
}

AVLNode create(int data[], int n){
    AVLNode root = NULL;
    for(int i=0; i<n; i++){
        insert(root, data[i]);
    }
    return root;
}
