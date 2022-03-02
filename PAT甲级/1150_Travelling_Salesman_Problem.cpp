#include <iostream>
#include <vector>
using namespace std;

int G[200+2][200+2];
int N, M;
int query(vector<int> &V){
    vector<int>::iterator it1 = V.begin(), it2 = it1+1;
    vector<int> vis(N+1, 0);
    int dist = 0;
    int flag = 0;  // == 1是TS cycle  == 2 不构成cycle
    vis[*it1]++;
    while(it2+1 != V.end()){
        if(!G[*it1][*it2]){
            cout << "NA (Not a TS cycle)" << endl;
            return 0;
        }
        dist += G[*it1][*it2];
        vis[*it2]++;
        it1++;it2++;
    }
    dist += G[*it1][*it2];

    cout << dist << " ";
    
    for(int i = 1; i <= N; i++){
        if(vis[i] == 0) flag = 2;  //存在没访问过的城市
        if(vis[i] > 1) flag = 1;    //是一个TS cycle
    }
    if(V.front() != V.back()) flag = 2;
    if(flag == 0) cout << "(TS simple cycle)" << endl;
    else if(flag == 1) cout << "(TS cycle)" << endl;
    else if(flag == 2) cout << "(Not a TS cycle)" << endl;
    if(flag == 2) return 0; //
    return dist;
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int c1, c2, d;
        cin >> c1 >> c2>> d;
        G[c1][c2] = d;
        G[c2][c1] = d;
    }
    int K, mindis = 1000, minid = 0;
    cin >> K;
    for(int i = 1; i <= K; i++){
        int n, t, dist;
        cin >> n;
        vector<int> V;
        while(n--){
            cin >> t;
            V.push_back(t);
        }
        cout << "Path " << i << ": ";
        dist = query(V);
        if(dist && dist < mindis){
            mindis = dist;
            minid = i;
        }
    }
    printf("Shortest Dist(%d) = %d\n", minid, mindis);
}
