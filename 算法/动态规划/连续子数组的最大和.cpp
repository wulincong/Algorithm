#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        vector<int> result;
        result.push_back(array[0]);
        int max = array[0];
        for(int i = 1; i < array.size(); i++) {
            // cout << result[i-1] << " ";
            if(result[i-1] <= 0) result.push_back(array[i]);
            else{
                result.push_back(array[i] + result[i-1]);
            }
            if(result[i] > max) max = result[i];
        }
        return max;
    }
};


int main(){
    vector<int> array = {1,-2,3,10,-4,7,2,-5};
    Solution s;
    cout << s.FindGreatestSumOfSubArray(array);
}