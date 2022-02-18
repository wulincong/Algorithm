#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;;
struct Node {
    int val;
    int level;
    Node * left = NULL, * right = NULL;
    Node(int v, int l):val(v), level(l){};
};

vector<Node*> V;

void InsertNode(Node * node, int n) {
    if(n > node->val){
        if(node->right == NULL){
            node->right = new Node(n, node->level + 1);
            V.push_back(node->right);
        }else InsertNode(node->right, n);
    }else{
        if(node->left == NULL){
            node->left = new Node(n, node->level + 1);
            V.push_back(node->left);
        }else InsertNode(node->left, n);
    }
}

bool cmp(Node * &a, Node * &b){
    return a->level < b->level;
}

int main(int argc, char **argv){
    int N, t;
    cin >> N;
    cin >> t;
    Node * root = new Node(t, 1);
    V.push_back(root);
    for(int i = 1; i < N; i++){
        cin >> t;
        InsertNode(root, t);
    }
    sort(V.begin(), V.end(), cmp);
    int max = V.back()->level;
    int cnt_max = 0, cnt_maxm1 = 0;
    for(int i = 0; i < N; i++){
        if(V[i]->level == max) cnt_max++;
        if(V[i]->level == max - 1) cnt_maxm1++;
    }
    cout << cnt_max << " + " << cnt_maxm1 << " = " << cnt_max+cnt_maxm1;
}
