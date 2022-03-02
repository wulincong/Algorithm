#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

int main_(){
    cin >> N;
    vector<int> V(N), M(N);
    for(int i = 0; i < N; i++){
        cin >> V[i];
        M[V[i]] = i;
    }
    vector<int> V_sorted = V;
    sort(V_sorted.begin(), V_sorted.end());
    int cnt = 0, idx_zero = M[0];
    
    while(V != V_sorted){
        if(idx_zero == 0){
            for(int i = 0; i < N; i++)if(V[i] != V_sorted[i]){
                // cout << i << endl;
                swap(V[0], V[i]);
                idx_zero = i;
                M[V[0]] = 0;
                break;
            }
        }else{
            // cout << idx_zero << " " << M[idx_zero] << endl;
            swap(V[idx_zero], V[M[idx_zero]]);
            idx_zero = M[idx_zero];
            // M[idx_zero] = idx_zero;
        }
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}

int main(){
    main_();
    // test();
}