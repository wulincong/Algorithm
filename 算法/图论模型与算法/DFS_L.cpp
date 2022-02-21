#include <bits/stdc++.h>

using namespace std;

const int MAXV = 1000;

vector<int> Adj[MAXV];
int n; 
bool vis[MAXV] = {false};

void DFS(int u, int depth){
    vis[u] = true;
    for(auto item : Adj[u]){
        if(vis[item] == false){
            DFS(item, depth + 1);
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

