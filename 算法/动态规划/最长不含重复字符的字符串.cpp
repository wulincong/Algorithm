#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param s string字符串 
     * @return int整型
     */
    int lengthOfLongestSubstring(string s) {
        // write code here
        vector<int> map(128, -1);  //记录字母上一次出现的位置
        vector<int> max;
        map[s[0]] = 0;
        max.push_back(1);
        for(int i = 1; i < s.size(); i++) {
            if(map[s[i]] == -1){  //这个字母以前没有出现过
                max.push_back(max[i-1] + 1);
                map[s[i]] = i;
            }else{
                int d = i - map[s[i]];
                if(d <= max[i-1]) max.push_back(d);
                else max.push_back(max[i-1]);
            }
        }
        int m = -1;
        for(auto it:max){
            if(it > m) m = it;
        }
        return m;
    }
};