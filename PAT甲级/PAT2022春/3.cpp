#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 1002;
int Tree[maxn];
int N;

bool is_BST(int root, int maxw, int minv){
    if(Tree[root] == -1) return true;
    if(Tree[root] < maxw && Tree[root] > minv){
        return is_BST(root * 2 + 1, Tree[root], minv) && 
        is_BST(root*2 +2, maxw, Tree[root]);
    }
    return false;
    
}

vector<int> inorderv;

void inOrder(int root){
    if(Tree[root] == -1) return;
    inOrder(root * 2 + 1);
    inorderv.push_back(Tree[root]); 
    inOrder(root * 2 + 2);
}

int main(){
    memset(Tree, -1, sizeof(Tree));
    cin >> N ;
    for(int i = 0; i < N; i++) cin >> Tree[i];
    if(is_BST(0, 1000003, -100)) cout << "YES" << endl;
    else cout << "NO" << endl;
    inOrder(0);
    for(int i = 0; i < inorderv.size(); i++){
        cout << inorderv[i];
        if(i != inorderv.size() - 1) cout << " ";
    } 
}