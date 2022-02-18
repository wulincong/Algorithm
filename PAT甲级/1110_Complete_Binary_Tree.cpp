#include <iostream>
#include <vector>

using namespace std;
const int maxv = 500;
vector<int> tleft(maxv, -1), tright(maxv, -1), root(maxv, -1);

bool check(int idx){
    if(tright[idx] == -1 && tleft[idx] == -1) return true;
    if(tright[idx] != -1 && tleft[idx] == -1) return false;
    if(tleft[idx] != -1) return check(tleft[idx]);
    if(tright[idx] != -1) return check(tright[idx]);
    return true;
}

int main() {
    int N, root_node;
    cin >> N;
    for(int i = 0; i < N; i++){
        string a, b;
        cin >> a >> b;
        if(a != "-"){
            tleft[i] = atoi(a.c_str());
            root[atoi(a.c_str())] = i;
        } 
        if(b != "-") {
            tright[i] = atoi(b.c_str());
            root[atoi(b.c_str())] = i;
        }

    }
    for(int i = 0; i < N; i++){
        if(root[i] == -1){
            root_node = i;
            break;
        }
    }
    if(check(root_node)){
        cout << "YES";
    }else{
        cout << "NO" << root_node;
    }

}