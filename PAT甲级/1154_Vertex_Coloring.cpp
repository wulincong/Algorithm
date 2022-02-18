#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **argv){
    int N, M, K, t;
    cin >> N >> M;
    vector< vector<int> > Map(N);
    vector<int> Color(N, -1);
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        Map[a].push_back(b);
        Map[b].push_back(a);
    }
    cin >> K;
    for(int i = 0; i < K; i++){
        int flag = 1;
        set<int> m_colors;
        for(int j = 0; j < N; j++){  //存颜色
            cin >> t;
            Color[j] = t;
            m_colors.insert(t);
        }
        for(int j = 0; j < N; j++){  // 看是否符合要求
            for(auto it : Map[j]){
                if(Color[j] == Color[it]){
                    flag = 0;
                    break;
                }
            }
            if(!flag) {
                cout << "No" << endl;
                break;
            }
        }
        if(flag){
            cout << m_colors.size() << "-coloring" << endl;
        }
    }
}