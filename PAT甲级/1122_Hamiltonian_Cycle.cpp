#include <iostream>
#include <vector>

using namespace std;
int N, M, K;
char G[200][200];

bool query(vector<int> & V){
    vector<bool> vis(N + 1, false);
    vector<int>::iterator it = V.begin();
    vis[*it] = true;
    if(*it != V.back()) return false;
    while(it + 2 != V.end()){
        if(G[*it][*(it+1)] && ! vis[*(it + 1)]){  //包含这条边并且没遍历过
            vis[*(it+1)] = true;
        }else return false;
        it++;
    }
    for(int i = 1; i < vis.size(); i++) if(vis[i] == false) return false;
    return true;
}

int main(int argc, char **argv){
    cin >> N >> M;
    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        G[a][b] = 1;
        G[b][a] = 1;
    }
    
    cin >> K;
    for(int i=0; i<K; i++){
        int n, t;
        cin >> n;
        vector<int> V;
        for(int i = 0; i < n; i++) {
            cin >> t;
            V.push_back(t);
        }
        if(query(V)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}

