const int MAXV = 1000;
const int INF = 10000000000;
int n, G[MAXV][MAXV];
bool vis[MAXV] = {false};

void DFS(int u, int depth){
    vis[u] = true;   //当前节点访问过
    for (int v = 0; v < n; v++){
        if(vis[v] == false && G[u][v] != INF){
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

