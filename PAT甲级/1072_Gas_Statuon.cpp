#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <string>
using namespace std;

const int INF = 2e5;
int Distance[1011][1011];
vector<int> G[1011];
int vis[1011];
int N, M, K, DS;

int id(string a){
    if(a[0] == 'G') return N + a[1] - '0';
    else return atoi(a.c_str());
}

vector<int> Dijkstra(int beg){
    memset(vis, 0, sizeof(vis));
    vector<int> D(N+M+1, INF);
    D[beg] = 0;
    for(int i = 0; i < N + M; i++){
        int nearest_idx, nearest_dis = INF;
        for(int i = 1; i <= M + N; i++)
            if(!vis[i] && D[i] < nearest_dis) nearest_dis = D[nearest_idx = i];
        vis[nearest_idx] = 1;
        for(int it:G[nearest_idx]){
            D[it] = min(D[nearest_idx] + Distance[nearest_idx][it], D[it]);
        }
    }
    return D;
}

int main(){
    cin >> N >> M >> K >> DS;
    for(int i = 0; i < K; i++){
        string a, b; int c;
        cin >> a >> b >> c;
        int ida = id(a), idb = id(b);
        G[ida].push_back(idb); G[idb].push_back(ida);
        Distance[ida][idb] = c;
        Distance[idb][ida] = c;
    }
    
    for(int i = N + 1; i <= M+N; i++){
        vector<int> D = Dijkstra(i);
        for(int it:D) cout << it << " ";
        cout << endl;
    }
}


