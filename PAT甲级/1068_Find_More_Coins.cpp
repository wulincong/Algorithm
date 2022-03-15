#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> Coins(N);
    for(int i=0; i<N; i++) cin >> Coins[i];
    sort(Coins.begin(), Coins.end());
    set<vector<int> > solutions;
    int flag = 0;
    do{
        vector<int> solution;
        int cnt = 0;
        for(int i = 0; i < N; i++){
            solution.push_back(Coins[i]);
            cnt += Coins[i];
            if(cnt == M){
                solutions.insert(solution);
                flag = 1;
                break;
            }else if(cnt > M) break;
        }
        if(flag == 1) break;
    }while(next_permutation(Coins.begin(), Coins.end()));
    if(!flag) cout << "No Solution" << endl;
    else for(auto it:solutions){
        for(int i = 0; i < it.size() - 1; i++)cout << it[i] << " ";
        cout << it[it.size() - 1];
        cout << endl;
    }
}