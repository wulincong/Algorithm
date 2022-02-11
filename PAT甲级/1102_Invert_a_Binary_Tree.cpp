#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

class Node{
public:
    string left, right;
    Node(string left, string right): left(left), right(right) {};
};

void LevelOrder(vector<Node> &nodes, int root_i) {
    queue<Node> Q;
    int curr = root_i;
    cout << root_i;
    Q.push(nodes[curr]);
    while(!Q.empty()){
        Node n = Q.front();
        Q.pop();
        if(n.left != "-") {
            int left = atoi(n.left.c_str());
            Q.push(nodes[left]);
            cout << " " << left;
        }
        if(n.right != "-") {
            int right = atoi(n.right.c_str());
            Q.push(nodes[right]);
            cout << " " << right;
        }
    }
}

void InOrder(vector<Node> &nodes, int root_i){
    
}

int main(int argc, char **argv){
    int N;
    cin >> N;
    vector<int> root(N, -1);
    vector<Node> nodes(N);
    for(int i = 0; i < N; i++){
        string lefts,rights;
        cin >> lefts >> rights;
        nodes[i] = Node(rights,lefts);
        if(lefts != "-") root[atoi(lefts.c_str())] = i;
        if(rights != "-") root[atoi(rights.c_str())] = i;
    }
    int root_i = 0;
    while(root[root_i] != -1){root_i = root[root_i];}
    LevelOrder(nodes, root_i);
    InOrder(nodes, root_i);
}