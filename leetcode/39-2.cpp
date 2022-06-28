#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    set<vector<int>> res_set;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> V;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, V);
        vector<vector<int>> res;
        for(auto it:res_set){
            res.push_back(move(it));
        }
        return res;
    }

    void dfs(vector<int>& candidates, int remain, vector<int> &V){
        if(remain == 0){
            vector<int> V_copy{V};
            sort(V_copy.begin(), V_copy.end());
            res_set.insert(V_copy);
            return;
        }
        for(int i:candidates){
            if(remain - i >=0){
                V.push_back(i);
                dfs(candidates, remain - i,V);
                V.pop_back();
            }else break;
        }
    }

};