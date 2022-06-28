#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> res;
    stack<char> s;
    vector<string> generateParenthesis(int n) {
        string str;
        dfs(n, str);
        return res;
    }
    void dfs(int remain, string str){
        if(remain == 0 && s.empty()){
            res.push_back(str);
            return;
        }
        //选择加入新的(
        if(remain > 0) {
            str.push_back('(');
            s.push(')');
            dfs(remain - 1, str);
            str.pop_back();s.pop();
        }
        //选择pop
        if(!s.empty()){
            str.push_back(s.top()); s.pop();
            dfs(remain, str);
            s.push(')');
        }
    }
};