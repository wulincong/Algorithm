#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 
     * 
     * @param grid int整型vector<vector<>> 
     * @return int整型
     */
    int maxValue(vector<vector<int> >& grid) {
        // write code here
        int dp[1000][1000];
        dp[1][1] = grid[0][0];
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int x = i+1, y = j+1;
                dp[x][y] = max(dp[x - 1][y], dp[x][y - 1]) + grid[i][j];
            }
        }

        return dp[n][m];
    }
};

int main(int argc, char **argv){
    
}



