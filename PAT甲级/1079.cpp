#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Node {
    int nid, level = 0, amount = 0;
    vector<int> childs;
    Node(int nid):nid(nid){}
};

int level_amount[100000];
int main(){
    int N;
    float P, r;
    cin >> N >> P >> r;
    vector<Node> V;
    for(int i = 0; i < N; i++) V.push_back(Node(i));
    for(int i = 0; i < N; i++){
        int K, t;
        cin >> K;
        Node curr = V[i];
        vector<int> V_child;
        for(int i = 0; i < K; i++){
            cin >> t;
            V[t].level = curr.level+1;
            V_child.push_back(t);
        }
        if(K == 0) cin >> V[i].amount;
        V[i].childs = V_child;
    }
    float cnt = 0.0;
    for(int i = 0; i < N; i++){
        if(V[i].amount) 
            level_amount[V[i].level] += V[i].amount;
    }
    for(int i = 0; i < 100; i++)if(level_amount[i]){
        cnt += level_amount[i] * P * pow(1.0+r*0.01, i);
    }
    printf("%.1f", cnt);
}