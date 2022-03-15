#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int mid, begin, end;
        vector<int> V(2, -1);
        if(nums.size() == 0) return V;
        mid = binary_search(nums, 0, nums.size() - 1, target);
        if(mid == -1) return V;
        // cout << mid << endl;
        begin = mid; end = mid;
        V[0] = begin; V[1] = end;
        while(-1 != (begin = binary_search(nums, 0, begin-1, target))){
            // cout <<"begin = " << begin << " ";
            V[0] = begin;
        }
        while(-1 != (end = binary_search(nums, end + 1, nums.size(), target))){
            // cout << "end = " << end << " ";
            V[1] = end;
        }
        return V;
    }

    int binary_search(vector<int>& nums, int beg, int end, int target) {
        if(beg < 0 || end < 0) return -1;
        if(beg > end) return -1;
        int mid = (beg + end) / 2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] > target) return binary_search(nums, beg, mid - 1, target);
        else return binary_search(nums, mid + 1, end, target);
    }

};

int main(){
    vector<int> V = {1};
    Solution S;
    vector<int> res = S.searchRange(V, 1);
    cout << res[0] << " " << res[1] <<endl;
}