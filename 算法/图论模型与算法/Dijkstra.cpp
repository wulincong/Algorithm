#include <bits/stdc++.h>
using namespace std;
const int INF = 10000000;
const int MAX = 1000;

int w[MAX][MAX];
int vis[MAX], d[MAX];

void Dijkstra(int n){
    for(int i = 0; i < n; i++) d[i] = (i == 0 ? 0 : INF);
    for(int i = 0; i < n; i++){
        int x, minw = INF;
        for(int y = 0; y < n; y++)if(!vis[y] && d[y] < minw) minw = d[x = y];
        vis[x] = 1;
        for(int y = 0; y < n; y++) d[y] = min(d[y], d[x]+w[x][y]);
    }

}


