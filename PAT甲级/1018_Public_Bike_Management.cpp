#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Station{
public:
    int bikes_num = 0;
    vector<int> neibors = vector<int>();
};

const int INF = 999999;
vector<Station> G(501);
int w[501][501];
int D[501], vis[501];
int N, Cmax, Sp, M, min_distance;

void Dijkstra(){
    memset(D, INF, sizeof(D));
    D[0] = 0;
    for(int i = 0; i < N; i++){
        //选择一个没经历过的最近距离的点
        int x, minw = INF;
        for(int y = 0; y < N; y++){
            if(!vis[y] && D[y] < minw){
                x = y;
                minw = D[y];
            }
        }
        vis[x] = 1;
        //从这个点出发更新邻接的距离
        for(auto y: G[x].neibors) D[y] = min(D[y], D[x]+w[x][y]);
    }
}

vector<vector<int> > routes;
int DFS(int u, int dis, vector<int> & route){
    // 从u出发深度优先遍历，到目标站停止遍历，就可以找到所有路径
    if(u == Sp && dis == min_distance){
        routes.push_back(route);
        return 1;
    }
    vis[u] = 1;
    for(int v: G[u].neibors){
        if(!vis[v]){
            route.push_back(v);
            DFS(v, dis+w[u][v], route);
            route.pop_back();
        }
    }
    return 0;
}

int bikes_sum(vector<int> & route){
    int cnt = 0;
    for(int i = 0; i < route.size() - 1 ; i++){
        cnt += G[route[i]].bikes_num;
    }
    return cnt;
}

int main(){
    cin >> Cmax >> N >> Sp >> M;
    for(int i = 1; i <=N; i++) cin >> G[i].bikes_num;
    // cout << G[1].bikes_num << endl;
    for(int i = 0; i < M; i++){
        int a, b, d;
        cin >> a >> b >> d;
        w[a][b] = d;
        G[a].neibors.push_back(b);
        G[b].neibors.push_back(a);
    }
    // cout << G[0].neibors.size() << endl;
    vector<int> route;
    Dijkstra();
    min_distance = D[Sp];
    // cout << min_distance << endl;
    memset(vis, 0, sizeof(vis));
    DFS(0, 0, route);
    // cout << routes.size() << endl;
    int best_route = 0, max_bikes = 0;
    for(int i = 0; i < routes.size(); i++){
        int s = bikes_sum(routes[i]);
        if(s > max_bikes){
            best_route = i;
            max_bikes =s;
        }
    }
    int need_bikes = routes[best_route].size() * (Cmax / 2) - max_bikes;
    cout << need_bikes << " " << 0;
    for(auto it : routes[best_route]){
        cout << "->" << it;
    }
    if(need_bikes > 0) cout << " " << 0;
    else cout << " " << -need_bikes;
}

