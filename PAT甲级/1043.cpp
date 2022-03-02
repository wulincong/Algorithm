#include <iostream>
using namespace std;
const static int maxn = 1000+5;
int preorder[maxn];
int tleft[50000], tright[50000];
int N;
bool isBST = true;

int findroot(int begin, int end){
    if(end < begin) return 0;
    int rootv = preorder[begin];
    int p = begin + 1;
    while(preorder[p] < rootv && p <= end) p++;
    int cnt = p - begin - 1;
    tleft[rootv] = findroot(begin + 1, begin + cnt);
    tright[rootv] = findroot(p, end);
    return rootv;
}

void BST(int root, int minv, int maxv){
    if(root < minv || root >= maxv) isBST = false;
    if(tleft[root]) BST(tleft[root], minv, root);
    if(tright[root]) BST(tright[root], root, maxv);
    cout << "end" << endl;
    return;
}

int main(){
    cin >> N;
    for(int i = 0 ; i < N; i++)
        cin >> preorder[i];
    int root = findroot(0, N-1);
    // BST(root, -10000, 10000000);
    // if(isBST) cout << "YES" << endl;
    cout << "NO" << endl;
}