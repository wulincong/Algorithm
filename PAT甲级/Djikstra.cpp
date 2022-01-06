#define MAXV 10
#define INF 100000000

int n, e[MAXV][MAXV];
int dis[MAXV], pre[MAXV]; //pre 用于标注当前节点的前一个结点
bool vis[MAXV] = {false};

void Dijkstra(int s){
    for (int i = 0; i < MAXV; i++) dis[i] = INF;
    dis[s] = 0;
    for(int i = 0; i < n; i++) pre[i] = i;  //初始状态当前节点前驱为自身
    for(int i = 0; i < n; i++){
        int u = -1, minn = INF;
        for(int j = 0; j < n; j++){
            if(vis[j] == false && dis[j] < minn){
                u = j;
                minn = dis[j];
            }
        }
    }
}
