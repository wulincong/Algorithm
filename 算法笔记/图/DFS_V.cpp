#include <bits/stdc++.h>

using namespace std;

const int MAXV = 1000;
const int INF = 10000000000;
int n, G[MAXV][MAXV];
int weight[MAXV];
bool vis[MAXV] = {false};

void DFS(int u){
    vis[u] = true;   //当前节点访问过
    cout << weight[u] << " ";
    for (int v = 0; v < n; v++){
        if(vis[v] == false && G[u][v] != INF){
            DFS(v);
        }
    }
}

void DFSTrave(){
    for(int u = 0; u < n; u++){
        if(vis[u] == false){
            DFS(u);
        }
    }
}

