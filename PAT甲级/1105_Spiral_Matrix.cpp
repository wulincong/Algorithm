#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool cmp(int a, int b) { return a > b; }
const static bool right_down = true;
const static bool left_up = false;
int main(){
    int N;
    cin >> N;
    vector<int> V;
    for(int i = 0; i < N; i++){
        int k;
        cin >> k;
        V.push_back(k);
    }
    //关键在于找到合适的m n; 从sqrt(N)向下递减，直到找到合适的
    int p;
    p = (int)(sqrt(N));
    while(N % p != 0) p--;
    int m = N / p, n = p;
    if(m < n) {
        int tmp = m; m = n; n = tmp;
    }
    //排序输出
    sort(V.begin(), V.end(), cmp);
    int M[m][n];
    bool direction = true;
    int index = 0;
    int x = 0, y = -1;
    int i = n, j = m - 1;
    while(i >= 0 && j >= 0) {
        if(direction == right_down){ //右上时向右k、i格，向下j格
            for(int k = 0; k < i; k++){M[x][++y] = V[index++];}
            for(int l = 0; l < j; l++){M[++x][y] = V[index++];}
        }
        else if(direction == left_up){
            for(int k = 0; k < i; k++){M[x][--y] = V[index++];}
            for(int l = 0; l < j; l++){M[--x][y] = V[index++];}
        }
        i--; j--;
        direction = !direction;
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << M[i][j];
            if(j < n - 1 ) cout << " ";
        }
        cout << endl;
    }
    return 0;
}









