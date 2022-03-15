#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

const int INF = 2e5;

class City{
public:
    string name;
    int happiness;
    vector<int> neibors;
};

vector<City> G(202);
map<string, int> city_name_to_index;
int Distance[202][202];
int vis[202];
int N, K, idx_start = 0, idx_end, min_distance;

vector<int> Dijkstra(int u){
    vector<int> D(N, INF);
    D[u] = 0;
    for(int i = 0; i < N; i++){
        int maxv = INF, x;
        for(int j = 0; j < N; j++) if(!vis[j] && D[j] < maxv)
            maxv = D[x = j];
        vis[x] = 1;
        for(int it:G[x].neibors)
            D[it] = min(D[it], D[x] + Distance[x][it]);
    }
    return D;
}

vector<vector<int>> routers;

void DFS(int u, int curr_dis, vector<int> &route){
    if(u == idx_end) {
        routers.push_back(route);
        return;
    }
    vis[u] = 1;
    for(int v:G[u].neibors){
        if(!vis[v] && curr_dis + Distance[u][v] <= min_distance){
            route.push_back(v);
            DFS(v, curr_dis + Distance[u][v], route);
            route.pop_back();
        }
    }
}

int main(){
    string start_city;
    cin >> N >> K >> start_city;
    city_name_to_index[start_city] = 0;
    G[0].name = start_city;
    for(int i = 1; i < N; i++) {
        cin >> G[i].name >> G[i].happiness;
        city_name_to_index[G[i].name] = i;
    }
    for(int i = 0; i < K; i++){
        string a, b; int d;
        cin >> a >> b >> d;
        int idxa = city_name_to_index[a];
        int idxb = city_name_to_index[b];
        G[idxa].neibors.push_back(idxb);
        G[idxb].neibors.push_back(idxa);
        Distance[idxa][idxb] = d; Distance[idxb][idxa] = d;
    }
    idx_end = city_name_to_index["ROM"];
    vector<int> D = Dijkstra(idx_start);
    min_distance = D[idx_end];
    vector<int> route;
    route.push_back(0);
    memset(vis, 0, sizeof(vis));
    DFS(idx_start, 0, route);
    for(auto v:routers){
        for(auto it:v)  cout<< G[it].name << " ";
        cout << endl;
    } 
}


