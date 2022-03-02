#include <bits/stdc++.h>
using namespace std;
vector<int> G[100];
int vis[100][100];
void euler(int u){
    for(auto v:G[u]) if(!vis[u][v]){
        vis[u][v] = vis[v][u] = 1;
        euler(v);
        cout << u << " " << v << endl;
    }
}
