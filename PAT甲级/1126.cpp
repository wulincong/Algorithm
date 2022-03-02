#include <iostream>
#include <vector>
using namespace std;
vector<int> G[500+2];
int N, M;

void printG(){
    for(int i = 1; i < N; i++){
        cout << G[i].size() << " ";
    }
    cout << G[N].size() << endl;
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a>> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int odd = 0;
    for(int i = 1; i <= N; i++)if(G[i].size() % 2 != 0) odd++;
    printG();
    if(odd == 0) cout << "Eulerian"<< endl;
    else if(odd == 2) cout << "Semi-Eulerian" << endl;
    else cout << "Non-Eulerian" << endl;
}
