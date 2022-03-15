#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return BinarySearch(nums, 0, nums.size() - 1, target);
    }
    int BinarySearch(vector<int> & nums, int beg, int end, int target) {
        if(beg > end) return -1;
        int mid = (beg + end) / 2;
        if(target == nums[mid]) return mid;
        if(nums[beg] <= nums[end]) {  //如果是有序的那一段
            if(nums[end] < target || nums[beg] > target) return -1; //
            else if(target > nums[mid]) return BinarySearch(nums, mid+1, end, target);
            else return BinarySearch(nums, beg, mid -1, target);
        }else{//无序
            int left = BinarySearch(nums, beg, mid, target);
            int right = BinarySearch(nums, mid + 1, end, target);
            if(right != -1) return right;
            else if(left != -1) return left;
            else return -1;
        }

    }
};

int main(){
    vector<int> nums = {1};
    int target = 0;
    Solution solution;
    cout << solution.search(nums, target) << endl;
}