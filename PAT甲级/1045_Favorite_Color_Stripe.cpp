#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<int, int> book;

int main(){
    int N, M, L;
    cin >> N;
    cin >> M;
    vector<int> favorite_colors_stripe(N);
    for(int i = 0; i < M; i++){
        cin >> favorite_colors_stripe[i];
        book[favorite_colors_stripe[i]] = i;
    }
    cin >> L;
    vector<int> all_colors_stripe;
    for(int i = 0; i < L; i++) {
        int t; cin >> t;
        if(book.count(t)) all_colors_stripe.push_back(t);  //筛选掉不喜欢的颜色
    }
    vector<int> DP(M, 0);
    for(int i:all_colors_stripe){
        //找出此颜色之前的DP最大值
        int maxc = 0, color_idx = 0;
        for(int j = 0; j <= book[i]; j++)if(DP[j] > maxc) maxc = DP[color_idx=j];
        //当前颜色DP最大值+1
        DP[book[i]] = DP[color_idx] + 1;
    }
    int maxc = 0, color_idx = 0;
    for(int j = 0; j < M; j++)if(DP[j] > maxc) maxc = DP[color_idx=j];
    cout << maxc;
}