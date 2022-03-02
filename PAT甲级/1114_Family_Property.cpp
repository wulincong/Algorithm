#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> G[10000];
int ID[10000];
int vis[10000];
int Nums[10000], Areas[10000];
void dfs(int u, int id){
    ID[u] = id;
    vis[u] = 1;
    for(auto it: G[u]){
        if(!vis[it]) dfs(it, id);
    }
}
int main(){
    int N;
    cin >> N;
    vector<int> hosts;
    for(int i=0; i<N; i++){
        int host, father, mother, childs_num;
        cin >> host >> father >> mother >> childs_num;
        if(father != -1 ){G[host].push_back(father); G[father].push_back(host);}
        if(mother != -1 ){G[host].push_back(mother); G[mother].push_back(host);}

        for(int j = 0; j < childs_num; j++){
            int child; cin >> child;
            G[host].push_back(child), G[child].push_back(host);
        }
        cin >> Nums[host] >> Areas[host];
        hosts.push_back(host);
    }
    int id = 1;
    for(int it : hosts){
        if(!vis[it]) {
            dfs(it, id);
            id++;
        }
    }
    cout << id;
}