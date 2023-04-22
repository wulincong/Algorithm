#include <iostream>
#include <unordered_map>
#include <sstream>
using namespace std;

int main() {
    int n;
    string line;
    unordered_map<int, int> freq;
    getline(cin, line);
    stringstream ss(line);
    // 统计每个元素出现的次数
    while (ss >> n) {
        freq[n]++;
    }

    int mode = -1, max_freq = 0;

    // 找到出现次数最多的元素
    for (auto p : freq) {
        if (p.second > max_freq) {
            max_freq = p.second;
            mode = p.first;
        }
    }

    cout << mode << endl;
    cout << max_freq<< endl;

    return 0;
}
