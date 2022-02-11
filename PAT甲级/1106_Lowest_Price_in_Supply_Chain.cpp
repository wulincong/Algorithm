#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int dept(vector<int> &root, int i){
    int cnt = 0;
    while(root[i] != -1){
        cnt++;
        i = root[i];
    }
    return cnt;
}

int main(int argc, char ** argv){
    int N, min_dept = 10000;
    float P, r;
    cin >> N >> P >> r ;
    vector<int> root(N, -1), depth(N, 0);
    vector<bool> is_retailer(N, false);
    for(int i=0; i<N; i++){
        int K;
        cin >> K;
        for(int j=0; j<K; j++){
            int tmp;
            cin >> tmp;
            root[tmp] = i;
        }
        if(K == 0) is_retailer[i] = true;
    }
    for(int i=0; i<N; i++){
        depth[i] = dept(root, i);
        if(is_retailer[i] && depth[i] < min_dept) min_dept = depth[i];
    }
    printf("%.4f ", P * pow(1 + r * 0.01, min_dept));
    int cnt = 0;
    for(int i=0; i<N; i++){
        if(depth[i] == min_dept && is_retailer[i]) cnt++;
    }
    cout << cnt << endl;
}

