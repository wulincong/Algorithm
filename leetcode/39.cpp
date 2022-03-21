#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int target;
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        for(int i = 0; i < candidates.size() - 1; i++) {
            if(candidates[i] == candidates[i + 1]) candidates.erase(candidates.begin() + i);
        }
        for(auto it:candidates) cout << it << " ";
        this->target = target;
        vector<int> arr;
        search(candidates, 0, arr, target);
        return res;
    }
    void search(vector<int>& candidates, int n, vector<int>& arr, int remain) {//n是当前遍历到哪一个了，remain是剩余量
        for(auto it:arr) cout << it << " ";
        cout << endl;
        cout << remain << endl;
        if(remain == 0) {
            res.push_back(arr);
            return;
        }else if(remain < 0 || n > candidates.size()) return; 
        arr.push_back(candidates[n]);
        search(candidates, n, arr, remain - arr[n]);
        arr.pop_back();
        arr.push_back(candidates[n+1]);
        search(candidates, n + 1, arr, remain - arr[n]);
        arr.pop_back();
        return;
    }
};

int main(){
    vector<int> candidates = {2,3,6,7};
    int target = 7;
    Solution s;
    s.combinationSum(candidates, target);
}