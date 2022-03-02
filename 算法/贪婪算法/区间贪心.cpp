#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 110;

struct Interval{
    int x,y;
    bool operator<(const Interval& other){
        if(this->x != other.x) return this->x > other.x;
        return this->y < other.y;
    }
}I[maxn];

int main(){
    int n;
    while(scanf("%d", &n), n!=0){
        for(int i=0; i<n; i++){
            scanf("%d %d", &I[i].x, &I[i].y);
        }
        sort(I, I+n);
        int ans = 1, lastX = I[0].x;
        for(int i=1; i<n; i++){
            if(I[i].y <= lastX){
                lastX = I[i].x;
                ans++;
            }
        printf("%d\n", ans);
        }
    }
}
