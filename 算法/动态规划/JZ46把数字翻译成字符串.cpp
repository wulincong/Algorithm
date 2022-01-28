#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    /**
     * 解码
     * @param nums string字符串 数字串
     * @return int整型
     */
    int solve(string nums) {
        // write code here
        if(nums.size() <= 2){
            int num = atoi(&nums[0]);
            if(num == 0) return 0; //
            else if(num <= 10) return 1;
            else if(num <= 26) return 2;
            else return 1;
        }
        vector<int> map(nums.size() + 1, 0);
        
        map[nums.size()] = nums[nums.size()] == '0' ? 0 : 1;
        if(nums[nums.size() - 1] == '0') map[nums.size() - 1] = 1;
        else if(nums[nums.size() - 1] <= '2' && nums[nums.size()] <= '5') map[nums.size()] = 2;
        else nums[nums.size()] = 1;

        for(int i = nums.size() - 2; i >= 0; i--){
            if(nums[i] <= '2' && nums[i] > '0' && nums[i+1] <= '5') 
                map[i] = map[i + 1] + map[i + 2];
            else map[i] = map[i + 1];
        }
        return map[0];
    }
};

