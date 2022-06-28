#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    set<vector<int>> res_set;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> V;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, V);
        vector<vector<int>> Res;
        for(auto it:res_set){
            Res.push_back(move(it));
        }
        return Res;
    }

    void dfs(vector<int>& candidates, int remain, int i, vector<int> & V){
        if(remain==0) {
            res_set.insert(V);return;}
        if(i >= candidates.size() || remain < 0) return;
        V.push_back(candidates[i]);
        dfs(candidates, remain - candidates[i], i+1, V);
        V.pop_back();
        dfs(candidates, remain, i+1, V);
    }
};
