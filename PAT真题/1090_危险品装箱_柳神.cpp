#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main() {
    int n, k, t1, t2;
    map<int,vector<int>> m;   //不兼容的字典
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> t1 >> t2;
        //构造双向的关系
        m[t1].push_back(t2);  
        m[t2].push_back(t1);
    }
    while (k--) {
        int cnt, flag = 0, a[100000] = {0};
        cin >> cnt;
        vector<int> v(cnt);  //存储集装箱内容信息
        for (int i = 0; i < cnt; i++) {
            scanf("%d", &v[i]);
            a[v[i]] = 1;  //对应物品在集装箱里
        }
        for (int i = 0; i < v.size(); i++)
            for (int j = 0; j < m[v[i]].size(); j++)
                if (a[m[v[i]][j]] == 1) flag = 1;
        printf("%s\n",flag ? "No" :"Yes");
    }
    return 0;
}