#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s_res, t_res;
        for(auto c:s) {
            if(c == '#') {
                if(s_res.size() > 0)
                    s_res.pop_back(); 
            }else s_res.push_back(c);}
        for(auto c:t) if(c == '#'){
            if(t_res.size() > 0)
                t_res.pop_back(); 
        } else t_res.push_back(c);
        return s_res == t_res;
    }
};