#include <bits/stdc++.h>

#define INF 10000000
#define MAX 1000

int w[MAX][MAX];

int min(int a, int b) {return a < b ? a : b;}

void Dijkstra(int n, int *v, int *d){
    for(int i = 0; i < n; i++){//v标记是否已经遍历过
        v[i] = 0;
    }
    for (int i = 0; i < n; i++) d[i] = (i == 0) ? 0 : INF; // 开始出了0距离自身是0，其他都是INF
    for (int i = 0; i < n; i++){
        int x, m = INF;
        for(int y = 0; y < n; y++) if(!v[y] && d[y] <= m) m = d[x = y];
        // 找到最小的未被遍历的节点
        v[x] = 1;  // 这个最小节点变成已遍历
        for(int y = 0; y < n; y++) d[y] = min(d[y], d[x] + w[x][y]);
        // 更新y距离
    }
}

