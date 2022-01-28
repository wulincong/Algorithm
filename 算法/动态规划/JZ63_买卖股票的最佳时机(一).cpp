#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * 
     * @param prices int整型vector 
     * @return int整型
     */
    int maxProfit(vector<int>& prices) {
        vector<int> min_A(prices.size(), -1);
        min_A[0] = prices[0];
        int max = 0;
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] > min_A[i-1]) min_A[i] = min_A[i-1];
            else min_A[i] = prices[i];
            if(prices[i] - min_A[i-1] > max) max = prices[i] - min_A[i-1];
        }
        return max;
        // write code here
    }
};

int main(){

}