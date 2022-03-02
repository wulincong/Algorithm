#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int root[20003];
int N, Q;

int findroot(int n){
    if(root[n] == 0) return n;
    else return findroot(root[n]);
}

void query(int a, int b){
    if(findroot(a) == findroot(b))
        cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main_(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        int k, t, root_idx = 10000+i;
        cin >> k;    
        for(int j = 0; j < k; j++){
            cin >> t;
            if(!root[t])
                root[t] = root_idx;
            else root[findroot(root[t])] = root_idx;
        }
    }
    cin >> Q;
    // cout << Q;    
    // cout << endl;
    int cnt = 0;
    for(int i = 10001; i <= 10000 + N; i++) if(root[i] == 0) cnt++;
    cout << cnt << " "; cnt = 0;
    for(int i = 1; i < 10000; i++)if(root[i]) cnt++;
    cout << cnt << endl;
    for(int i = 0; i < Q; i++){
        int a,b;
        cin >> a >>b;
        query(a, b);
    }
    return 0;
}

void test(){

}

int main(){
    main_();
    test();
}

