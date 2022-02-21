#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int tleft[30+5], tright[30+5], postorder[30+5], inorder[30+5];
int N;
int findroot(int post_begin, int post_end, int in_begin, int in_end){
    if(post_begin > post_end) return 0;
    int root = postorder[post_end];
    int p = in_begin;
    while(inorder[p] != root) p++;
    int cnt = p - in_begin;
    tleft[root] = findroot(post_begin, post_begin + cnt - 1, in_begin, p-1);
    tright[root] = findroot(post_begin + cnt, post_end - 1, p + 1, in_end);
    return root;
}

void levelorder(int root){
    queue<int> q;
    vector<int> vis;
    q.push(root);
    while (!q.empty())
    {
        int r = q.front(); q.pop();
        vis.push_back(r);
        if(tleft[r]) q.push(tleft[r]);
        if(tright[r]) q.push(tright[r]);
    }
    for(int i = 0; i < vis.size() - 1; i++) cout << vis[i] << " ";
    cout << vis[vis.size() - 1];
}

int main(int argc, char **argv){
    cin >> N;
    for(int i=1; i<=N; i++) cin >> postorder[i];
    for(int i=1; i<=N; i++) cin >> inorder[i];
    int root = findroot(1, N, 1, N);
    levelorder(root);
}
