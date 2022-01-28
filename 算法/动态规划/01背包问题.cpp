#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, V;
    vector<int> weights(n+1, 0), values(n+1, 0);
    cin >> n >> V;
    for(int i = 1; i <= n; i++) cin >> weights[i];
    for(int i = 1; i <= n; i++) cin >> values[i];
    int dp[n+1][V+1] = {0};
    for(int i = 0; i <= n; i++) for(int j = 0; j <= V; j++) dp[i][j] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = weights[i]; j <= V; j++){
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-weights[i]] + values[i]);
        }
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= V; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << dp[n][V] << endl;
}


