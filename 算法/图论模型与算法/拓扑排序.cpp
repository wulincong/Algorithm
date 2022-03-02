#include <bits/stdc++.h>
using namespace std;
const int MAXV = 1000;
int vis[MAXV];   // =0表四未访问，=1表示已访问，=-1表示正在访问
vector<int> topo;
vector<int> G[MAXV];
bool DFS(int u){
    vis[u] = -1;
    for(auto v:G[u]){
        if(vis[v] < 0) return false;
        else if(!vis[v] && !DFS(v)) return false;
    }
    vis[u] = 1;
    topo.push_back(u);
    return true;
}

