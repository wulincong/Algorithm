#include <cstdio>
#include <vector>

using namespace std;

typedef struct BSNode{
    int data;
    struct BSNode *next, *prev;
} * BTNode, BTree;

bool isMirror;
vector<int> origin, pre, preM, post, postM;

void insert(BTNode &root, int data){

}

void preOrder(BTNode &root, vector<int> &vi){

}
void preOrderM(BTNode &root, vector<int> &vi){

}
void postOrder(BTNode &root, vector<int> &vi){

}
void postOrderM(BTNode &root, vector<int> &vi){

}


int main(int argc, char **argv){
    int n, data;
    BTNode root = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &data);
        origin.push_back(data);
        insert(root, data);  //根据所给元素构建二叉排序树
    }
    preOrder(root, pre);  //先序遍历
    preOrderM(root, preM); //镜像先序遍历
    postOrder(root, post);  // 后序遍历
    postOrderM(root, postM);  // 镜像后续遍历
    if(origin == pre){
        printf("YES\n");
        for(int i = 0; i < post.size(); i++){
            printf("%d", post[i]);
            if(i < post.size() - 1) printf(" ");
        }
    }else if(origin == preM){
        printf("YES\n");
        for(int i = 0; i < postM.size(); i++){
            printf("%d", postM[i]);
            if(i < postM.size() - 1) printf(" ");
        }
    }else{
        printf("NO\n");
    }
    return 0;
}