#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

struct Node{
    int val;
    int deep;
    int component;  //连通分量编号
    vector<int> edge;
    Node(int v):val(v){}

};

vector<Node *>  G;

int visited[10000+5];

int BFS(Node * node, int component){
    queue<Node*> q;
    node->deep = 1;
    q.push(node);
    int cnt;  //统计有多少相邻边已经被访问
    int is_cycle = 0;
    int max_deep = 0;
    while(!q.empty()){
        Node * n= q.front(); q.pop(); 
        cnt = 0;
        visited[n->val] = 1;
        n->component = component;
        for(int i = 0; i < n->edge.size(); i++){
            if(visited[n->edge[i]]) cnt++;
            else {
                Node * child = G[n->edge[i]]; 
                q.push(child);
                child->deep = n->deep + 1;
                if(n->deep + 1 > max_deep) max_deep = n->deep + 1;
            }
        }
        if(cnt > 1) is_cycle = 1;
    }
    if(is_cycle) return -1;
    else return max_deep;
}

bool is_visited(int N){
    for(int i = 1; i <= N; i++){
        if(! visited[i]) return false;
    }
    return true;
}

int main(){
    int N;
    cin >> N;
    Node * n = new Node(0);
    G.push_back(n);
    for(int i = 1; i <= N; i++){
        Node * node = new Node(i);
        G.push_back(node);
    }
    for(int i = 1; i < N; i++){
        int a,b;
        cin >> a>> b;
        G[a]->edge.push_back(b);
        G[b]->edge.push_back(a);
    }
    int component = 0;
    int flag = 0;  //flag = 1表示有环,flag = 2表示连通分量>1    
    for(int i = 1; i < N; i++){
        if(! visited[i]) {
            component++;
            Node * node = G[i];
            if( BFS(node, component) == -1) flag = 1;
        }
    }
    if(flag == 1 || component > 1){
        cout << "Error: " << component  << " components" << endl;
    }else{
        vector<int> max_deep(N+1, 0);
        int max = 0;
        for(int i = 1; i <= N; i++){
            memset(visited, 0, sizeof(visited));
            max_deep[i] = BFS(G[i], 1);
            if(max_deep[i] > max) max = max_deep[i];
        }
        for(int i = 1; i <= N ;i++){
            // cout << max_deep[i] << " ";
            if(max_deep[i] == max)cout << i << endl;
        }
    } 
}


