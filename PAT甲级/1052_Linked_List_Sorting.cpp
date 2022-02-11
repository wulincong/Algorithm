#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
class Node{
public:
    Node(int a, int b, int c);
    int Address, Key, Next;
};

Node::Node(int a, int b, int c):
        Address(a), Key(b), Next(c){}

bool cmp(Node& a, Node& b){
    return a.Key < b.Key;
}

int main(int argc, char **argv){
    int N, begin;
    cin >> N >> begin;
    cout.fill('0');
    vector<Node> nodes;
    for(int i = 0; i < N; i++){
        int a, b, c;
        cin >> a >> b >> c;
        nodes.push_back(Node(a, b, c));
    }
    sort(nodes.begin(), nodes.end(), cmp);
    cout << N << " " << nodes[0].Address << endl;
    for(int i = 0; i < N - 1; i++){
        nodes[i].Next = nodes[i + 1].Address;
        cout.width(5);
        cout << nodes[i].Address << " " << nodes[i].Key << " ";
        cout.width(5);
        cout << nodes[i].Next << endl;
    }
    cout.width(5);
    cout << nodes[N-1].Address << " " 
    << nodes[N-1].Key << " -1" << endl;
    return 0;
}

