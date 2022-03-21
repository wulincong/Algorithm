#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        set<string> Set;
        vector<int> result;
        int l_p = p.size();
        do{
            Set.insert(p);
        }while(next_permutation(p.begin(), p.end()));
        for(int i =0; i < s.size() - l_p; i++){
            string t = s.substr(i, l_p);
            if(Set.count(t)) result.push_back(i);
        }
        return result;
    }
};