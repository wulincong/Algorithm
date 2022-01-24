#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Supplier{
public:
    int up_Supplier;
    vector<Supplier *> down_Suppliers;
    int deep;
};

void BFS(Supplier *root_supplier, int deep){
    root_supplier->deep = deep;
    if(root_supplier->down_Suppliers.size() == 0) return;
    else{
        for(auto it : root_supplier->down_Suppliers){
            BFS(it, deep + 1);
        }
    }
}

int main(){
    int N, up, root; 
    float P, r;
    cin >> N >> P >> r;
    vector<Supplier> suppliers(N);
    for(int i = 0; i < N; i++){
        cin >> up;
        suppliers[i].up_Supplier = up;
        if(up != -1)
            suppliers[up].down_Suppliers.push_back(&suppliers[i]);
        else root = i;
    }
    Supplier *root_supplier = &suppliers[root];
    BFS(root_supplier,0);
    int max_deep = 0;
    int cnt = 0;
    for(int i = 0; i < N; i++){
        if(suppliers[i].deep == max_deep) cnt++;
        else if(suppliers[i].deep > max_deep){
            max_deep = suppliers[i].deep;
            cnt = 1;
        }
    }
    cout << max_deep << cnt << endl;
    float max_Price = P * pow(1 + r * 0.01, cnt);
    printf("%.2f", max_Price + 0.005);
}





