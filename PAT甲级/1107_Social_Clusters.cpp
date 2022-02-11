#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findRoot(vector<int> &root, int i) {
    while(root[i] != -1){
        i = root[i];
    }
    return i;
}

bool cmp(int a, int b) {
    return a > b;
}

int main(int argc, char **argv){
    int N, cnt = 0;
    cin >> N;
    vector<int> root(N, -1), Count(N, 0);
    for(int i=1; i<N; i++){
        int k, tmp, r;
        char t;
        cin >> k >> t >> r;
        for(int j=1; j<k; j++){
            cin >> tmp;
            root[tmp] = r;
        }
        if(root[k] != -1){
            Count[findRoot(root, k)] += 1;
        }else{
            Count[k] += 1;
        }
    }
    for(int i=1; i<N; i++) if(root[i] == -1) cnt++;
    cout << cnt << " " << endl;
    sort(Count.begin(), Count.end(), cmp);
    // cout << Count[0];
    for(int i = 1; i < N; i++){
        if(Count[i] > 0)
        cout << " " << Count[i];
    }
}
