#include <iostream>
#include <vector>

using namespace std;

class Node{
public:
    int val,next;
    Node(int val, int next) : val(val),next(next){}
};

int main(int argc, char **argv){
    bool isExist[20005] = {false};
    bool *isExistP = isExist + 10000;
    vector<Node> nodes(100002);
    vector<bool> output(100002, false), removed(100002, false);
    int first, N;
    cin >> first >> N;
    for(int i = 0; i < N; i++){
        int a,b,c;
        cin >> a >> b >> c;
        nodes[a] = Node(b,c);
    }
    int curr = first;
    while(nodes[curr].next != -1){
        if(isExistP[nodes[curr].val]){  //已经存在了这个值，加入到removed
            removed[curr] = true;
        }else{
            output[curr] = true;
            printf("%05d %d %05d\n", curr,nodes[curr].val, nodes[curr].next);
            cout << nodes[curr].val << " ";
        }
        curr = nodes[curr].next;
    }
    curr = first;
    while(nodes[curr].next != -1){
        if(removed[curr]){
            printf("%05d %d %05d\n", curr,nodes[curr].val, nodes[curr].next);
        }
        curr = nodes[curr].next;
    }

}


