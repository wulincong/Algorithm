#include <iostream>

using namespace std;

typedef struct TreeNode{
    int ID, level, childs_num;
    struct TreeNode * childs[100];
} *TNode, T;

int main(){
    int N, M, max_level = 1;
    cin >> N >> M;
    static TNode family[101];
    for(int i=0; i<101; i++) family[i] = NULL;
    if(N == 0) return 0;
    for(int i = 0; i < N; i++){
        int ID, K, child_ID;
        cin >> ID >> K;
        TNode parent;
        if(family[ID] == NULL){ //如果不存在该节点
            parent = new T;
            parent->ID = ID;
            if(ID == 1) parent->level = 1;
            family[ID] = parent;
        }
        else parent = family[ID];   //已存在该节点
        parent->childs_num = K;
        for(int j = 0; j < K; j++){
            cin >> child_ID;
            TNode child = new T;
            // 初始化孩子节点
            child->level = parent->level + 1; child->ID = child_ID; child->childs_num = 0;
            family[child_ID] = child;
            parent->childs[j] = child;
            if(child->level > max_level) max_level = child->level;
        }
    }
    int cnt[101] = {0};
    for(int i = 0; i < 101; i++ ){
        if(family[i] != NULL && family[i]->childs_num == 0){
            cnt[family[i]->level]++;
        }
    }
    for(int i = 1; i <= max_level; i++){
        cout << cnt[i];
        if(i != max_level) cout << " ";
    }

    return 0;
}
