#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        this->q_nums = nums;
        vector<int> tmp_nums;
        next_subset(tmp_nums, 0);
        for(auto it: Set){
            res.push_back(it);
        }
        return this->res;
    }

    vector<vector<int>> res;
    set<vector<int>> Set;
    vector<int> q_nums;
    void next_subset(vector<int>& tnums, int n){
        if(q_nums.size() == n) {
            Set.insert(tnums);
            return;
        }
        next_subset(tnums, n + 1);
        tnums.push_back(q_nums[n]);
        next_subset(tnums, n + 1);
        tnums.pop_back();
    }
};