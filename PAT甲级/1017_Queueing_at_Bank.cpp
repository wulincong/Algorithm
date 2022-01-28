#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 10005;
struct person {
    int come = 28800, time = 0;
} p[maxn];
int cmp(person p1, person p2) { return p1.come < p2.come; }
int n, k, cnt = 0, total_wait;
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        int hh, ss, mm, tt;
        scanf("%d:%d:%d %d", &hh, &mm, &ss, &tt);
        int sum = hh * 3600 + mm * 60 + ss;
        if (sum > 61200) continue;  //超过17点的不接待
        p[++cnt].time = tt > 60 ? 3600 : tt * 60;
        p[cnt].come = sum;
    }
    sort(p + 1, p + 1 + cnt, cmp);
    vector<int> server(k, 28800);   //窗口服务
    int curr = 1;  //记录当前要被服务人
    for(int i = 0; i < k; i++){
        total_wait += server[i] - p[curr].come;
        server[i] += p[curr++].time;
    }
    while(curr <= cnt){
        int min = 0;
        for(int i = 0; i < k; i++) if(server[i] < server[min]) min = i;
        total_wait += server[min] - p[curr].come;
        server[min] += p[curr].time;
        curr++;
    }
    (!cnt) ? printf("0.0\n") : printf("%.1lf", ((double)total_wait/60.0)/(double) cnt);
    return 0;
}
