#include <iostream>
using namespace std;

const int n = 8;
int tot = 0;
int C[9];
void search(int cur){
    if(cur == n) {
        tot++;
        for(int i=0; i<n; i++)
            cout << C[i] << " "; 
        cout << endl;
    }
    else for(int i=0; i<n; i++){
        int ok = 1;
        C[cur] = i;
        for(int j = 0; j < cur; j++){
            if( C[j] == i || cur - C[cur] == j - C[j] || cur + C[cur] == j + C[j] ){
                ok = 0; break;
            } 
        }
        if(ok) search(cur + 1);
    }
}

int vis[n][3];


int main(){
    search(0);
    cout << tot;
}
