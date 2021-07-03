#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char **argv){
    int N = 10, p = 8, t, maxLenth = 0;
    cin >> N >> p;
    vector<int> v(N);
    for (int i = 0; i < N; i ++) cin >> v[i];
    sort(v.begin(), v.end());
    for (int i = 0; i < N; i++){
        if(maxLenth + i > N) break;
        int tempM = v[i] * p;
        for(int j = N; j > i; j--){
            t = j - i + 1;
            if(v[j] <= tempM && t > maxLenth) 
                maxLenth = t;
            // else break;
        }
    }
    printf("%d\n", maxLenth);

}