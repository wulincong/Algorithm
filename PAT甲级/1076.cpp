#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int level[100+5], visited[100+5];
vector<int> G[100+5];
int L;
void BFS(int u){ //只遍历l层
    memset(level, -1, sizeof(level));
    memset(visited, 0, sizeof(visited));
    level[u] = 0;
    queue<int> q;
    q.push(u);
    while(!q.empty()){
        int curr = q.front(); q.pop();
        visited[curr] = 1;
        if(level[curr] == L) continue;
        for(int i = 0; i < G[curr].size(); i++){
            if(!visited[G[curr][i]]){
                q.push(G[curr][i]);
                level[G[curr][i]] = level[curr] + 1;
            }
        }
    }
}

int query(int u){
    BFS(u);
    int cnt = -1;
    for(int i = 0; i < 101; i++) if(visited[i]) cnt++;
    return cnt; 
}

int main(){
    int N, n, t;
    cin >> N >> L;
    for(int i = 1; i <= N; i++){
        cin >> n;
        //可以对输入做优化
        for(int j = 0; j < n; j++){
            cin >> t;
            G[t].push_back(i);
        }
    }
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> t;
        cout << query(t) << endl;
    }

}

