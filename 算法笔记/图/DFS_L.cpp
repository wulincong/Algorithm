#include <iostream>
#include <vector>

const int MAXV = 1000;

vector<int> Adj[MAXV];
int n; 
bool vis[MAXV] = {false};

void DFS(int u, int depth){
    vis[u] = true;
    for(int i = 0; i < Adj[u].size(); i++){
        int v = Adj[u][i];
        if(vis[v] == false){
            DFS(v, depth + 1);
        }
    }
}

void DFSTrave(){
    for(int u = 0; u < n; u++){
        if(vis[u] == false){
            DFS(u, 1);
        }
    }
}

