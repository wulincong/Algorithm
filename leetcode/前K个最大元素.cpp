#include <bits/stdc++.h>
using namespace std;


void Solution(vector<int>& nums, int k) {
    map<int, int> frequencyDict;
    using PairI = std::pair<int, int>;
    priority_queue<PairI, vector<PairI>, greater<PairI>> priorityQueue;
    
    for (auto e : nums) frequencyDict[e]++;
    
    for (auto & pair : frequencyDict) {
        priorityQueue.emplace(pair.second, pair.first);
        //如果队列长度超过K，超出的部分可以截掉
        if (priorityQueue.size() > k) priorityQueue.pop();
    }
    cout<< "[";
    while (!priorityQueue.empty()) {
        cout << priorityQueue.top().second;
        priorityQueue.pop();
        if(!priorityQueue.empty())cout << ",";
    }
    cout << "]";
    return;
}

int main(int argc, char ** argv){

    // vector<int> nums = {1,1,1,2,2,3};
    // int k = 2;


    string inputs;
    vector<int> nums;
    getline(cin, inputs);
    int k;
    stringstream ss(inputs);

    while(getline(ss, inputs, ',')){
        int tmp = stoi(inputs);
        nums.push_back(tmp);
    };

    cin >> k;
    Solution(nums, k);
}