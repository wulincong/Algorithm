#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> diamonds;
    diamonds.push_back(0);
    for(int i = 0; i < N; i++){
        int k;
        cin >> k;
        diamonds.push_back(k);
    }
    vector<int> A(N, -1), S_A(N, -1);
    int second = M + 10000000;
    for(int i = 1; i <= N; i++){
        int sum = 0, j = i;
        while (sum < M && j > 0){sum += diamonds[j--];}
        if(sum >= M) {
            if(sum != M && sum < second) second = sum;
            A[i] = j + 1;
            S_A[i] = sum;
        }
    }
    bool flag = false;
    for(int j = 1; j <= N; j++){
        if(S_A[j] == M){
            flag = true;
            cout << A[j] << "-" << j << endl;
        }
    }
    if(!flag){
    for(int j = 1; j <= N; j++){
        if(S_A[j] == second)
            cout << A[j] << "-" << j << endl;
    }
    }
}

