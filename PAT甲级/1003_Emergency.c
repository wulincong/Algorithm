#include <stdio.h>

#define N 500
#define INF 1000000

int VerTex[N][N];
int vis[N], d[N], w[N], num[N];
int n, m, c1, c2;
int t1, t2, weight;
int weights[N];

void Dijkstra(int s){//s是起点
    for(int i = 0; i < n; i++){
        int u = -1, MIN = INF;  //u使d[u]最小，MIN存放该最小的d[u]
        for(int j = 0; j < n; j++){  //找出未访问节点中距离最近的
            if(!vis[j] && d[j] < MIN){
                u = j;
                MIN = d[j];
            }
        }
        if(u == -1) return; //找不到小于INF的d[u],顶点不连通
        vis[u] = 1;
        for(int v = 0; v < n; v++){ 
            //邻居的更新
            if( !vis[v] && VerTex[u][v] != INF){
                if(d[u] + VerTex[u][v] < d[v]){//以u为中介可以让d[v]更小
                    d[v] = d[u] + VerTex[u][v];
                    w[v] = w[u] + weights[v];
                    num[v] = num[u];
                }else if(d[u] + VerTex[u][v] == d[v]){  //路径长度相同
                    if(w[u] + weights[v] > w[v]){ //可以找到更多团队
                        w[v] = w[u] + weights[v];
                    }
                    num[v] += num[u];
                }
            }
        }
    }
}

int main(int argc, char **argv){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)VerTex[i][j] = i == j ? 0 : INF;
    }
    scanf("%d %d %d %d",&n,&m,&c1,&c2);
    for(int i = 0; i < n; i++){
        scanf("%d", &weights[i]);
    }
    for(int i=0; i<m; i++){
        scanf("%d %d %d",&t1,&t2,&weight);
        VerTex[t1][t2] = weight;
        VerTex[t2][t1] = weight;
    }
    for(int i=0; i<n; i++) {
        vis[i] = 0;
        d[i] = INF;
        num[i] = 0;    
        w[i] = 0;
    }
    w[c1] = weights[c1];
    num[c1] = 1;

    Dijkstra(c1);
    printf("%d %d\n", num[c2], w[c2]);
    return 0;
}