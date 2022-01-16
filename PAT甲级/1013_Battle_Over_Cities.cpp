#include <iostream>
using namespace std;
bool map[1000][1000] = {false};

int pick(short *con, int end){
    for(int i = 1; i <= end; i++){
        if(con[i] == 0)
            return i;
    }
    return 0;
}

void occupied(int N, int city){
    short connected[1000] = {0};
    connected[city] = -1;
    int cnt = -1;
    while(int p = pick(connected, N)){
        cnt++;
        connected[p] = 1;
        for(int i = 0; i < N; i++){
            if(map[p][i] == true){
                connected[i] = 1;
            }
        }
    }
    cout << cnt;
}

int main(int argc, char **argv){
    int N, M, K, a, b, city;
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++){
        cin >> a >> b; 
        map[a][b] = true;
        map[b][a] = true;
    }
    for(int i = 1; i <= K; i++){
        cin >> city;
        occupied(N, city);
        if(i != K) cout << " ";
    }
}



