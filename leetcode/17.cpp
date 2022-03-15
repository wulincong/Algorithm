#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> res;
    map<char, string> M;
    vector<string> letterCombinations(string digits) {
        M['2'] = "abc"; M['3'] = "def"; M['4'] = "ghi"; M['5'] = "jkl";
        M['6'] = "mno"; M['7'] = "pqrs"; M['8'] = "tuv"; M['9'] = "wxyz";
        string s = "";
        DFS(digits, 0, s);    
        return this->res;    
    }

    void DFS(string &digits, int curr, string &s){
        if(curr == digits.size()) {
            res.push_back(s);
            return;
        }else{
            for(char it:M[digits[curr]]){
                s.push_back(it);
                DFS(digits, curr+1, s);
                s.pop_back();
            }
        }
    }
};

int main(){
    Solution s;
    string str;
    cin >> str;
    vector<string> V = s.letterCombinations(str);
    for(string it:V) cout << it << endl;
}