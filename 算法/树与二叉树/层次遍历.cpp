#include <bits/stdc++.h>
using namespace std;

struct Node{
    bool have_value;
    int v;
    Node *left, *right;
    Node():have_value{false}, left(NULL), right(NULL){}
};

Node * root;

Node * newnode(){ return new Node();}

bool bfs(vector<int> & ans){
    queue<Node *> q;
    ans.clear();
    q.push(root);
    while(! q.empty()){
        Node * u = q.front(); q.pop();
        if(!u->have_value) return false; 
        ans.push_back(u->v);
        if(u->left != NULL) q.push(u->left);
        if(u->right != NULL) q.push(u->right);
    }
    return true;
}

int tleft[10], tright[10], thave_value[10];
const int troot = 1;
int cnt = 0;
void tnewtree(){ 
    tleft[troot] = tright[troot] = 0; 
    thave_value[troot] = false; 
    cnt = troot;
}

int tnewnode() { 
    int u = ++cnt; tleft[u] = tright[u] = 0; 
    thave_value[troot] = false; 
    return u; 
}

