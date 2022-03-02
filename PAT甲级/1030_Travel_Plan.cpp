#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> G[501];
const int INF = 9999;
int cost[501][501];
int Distance[501][501];
int N, M;
int vis[501];
int NDistance[501];

void Dijkstra(int beg){
    memset(vis, 0, sizeof(vis));
    memset(NDistance, INF, sizeof(NDistance));
    NDistance[beg] = 0;
    for(int i = 0; i < N; i++){
        int min_d = INF, u;
        for(int j = 0; j < N; j++) if(!vis[j]){
            if(NDistance[j] < min_d) {
                min_d = NDistance[j];
                u = j;
            }
        }
        vis[u] = 1;
        for(int v: G[u]){
            NDistance[v] = min(NDistance[v], NDistance[u] + Distance[u][v]);
        }
    }
}

int main(){
    int S, D;
    cin >> N >> M >> S >> D;
    for(int i = 0; i < M; i++){
        int a, b, d, c;
        cin >> a >> b >> d >> c;
        G[a].push_back(b); G[b].push_back(a);
        cost[a][b] = c; cost[b][a] = c;
        Distance[a][b] = d; Distance[b][a] = d;
    }
    Dijkstra(S);
    cout << NDistance[D] << endl;

}

