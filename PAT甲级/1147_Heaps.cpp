#include <iostream>
#include <vector>
using namespace std;

bool isMaxHeap(vector<int> & V, int root) {
    if(root > V.size()) return true;
    bool flag = true;
    if(root * 2 + 1 < V.size() && V[root * 2 + 1] > V[root]) flag = false;
    if(root * 2 + 2 < V.size() && V[root * 2 + 2] > V[root]) flag = false;
    return flag && isMaxHeap(V, root * 2 + 1) && isMaxHeap(V, root * 2 + 2);
}

bool isMinHeap(vector<int> & V, int root) {
    if(root > V.size()) return true;
    bool flag = true;
    if(root * 2 + 1 < V.size() && V[root * 2 + 1] < V[root]) flag = false;
    if(root * 2 + 2 < V.size() && V[root * 2 + 2] < V[root]) flag = false;
    return flag && isMinHeap(V, root * 2 + 1) && isMinHeap(V, root * 2 + 2);
}

vector<int> postorder_list;

void postorder(vector<int> & V, int root) {
    if(root + 1 > V.size()) return;
    postorder(V, root * 2 + 1);
    postorder(V, root * 2 + 2);
    postorder_list.push_back(V[root]);
}

void debug(){
    vector<int> V = {98, 72, 86, 60, 65, 12, 23, 50};
    postorder(V, 0);
    for(int i = 0; i < postorder_list.size(); i++){
        cout << postorder_list[i] ;
        if(i + 1 < postorder_list.size())
            cout << " ";
    }
    cout << endl;
}

void main_(){
    int M, N;
    cin >> M >> N;
    for(int i = 0; i < M; i++) {
        vector<int> V;
        for(int j = 0; j < N; j++){
            int t;
            cin >> t;
            V.push_back(t);
        }
        if(V[0] > V[1]){  //可能是大顶堆
            if(isMaxHeap(V, 0)) cout << "Max Heap" << endl;
            else cout << "Not Heap" << endl;
        }
        else {
            if(isMinHeap(V, 0)) cout << "Min Heap" << endl;
            else cout << "Not Heap" << endl;
        }
        postorder(V, 0);
        for(int i = 0; i < postorder_list.size(); i++){
            cout << postorder_list[i] ;
            if(i + 1 < postorder_list.size())
                cout << " ";
        }
        cout << endl;
        postorder_list.clear();
    }
}

int main() {
    // debug();
    main_();
}

