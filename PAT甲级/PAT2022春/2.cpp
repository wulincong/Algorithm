#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <map>

using namespace std;
/*
10 4
40 25 60 -15 30 -21 80 -1 -5 27
*/

map<int, int> M;
int N, K;

void InsertM(int a){
    if(M.count(a)) M[a]++;
    else M[a] = 1;
    if(M.size() > K) M.erase(M.begin());
}

int main_(){
    cin >> N >> K;
    // string str;
    // getline(cin, str);
    // getline(cin, str);
    // stringstream ss(str);
    vector<int> V;
    for(int i = 0; i < N; i++) {
        int n; 
        scanf("%d", &n);
        // ss >> n;
        InsertM(n);
    }
    int cnt = 0;
    for(auto it = M.rbegin(); it != M.rend(); it++){
        for(int i = 0; i < it->second; i++){
            cout << it->first;
            cnt++;
            if(cnt < K) cout << " ";
            if(cnt >= K) break;
        }
        if(cnt >= K) break;
    }
    cout << endl;
    return 0;
}

int main(){
    main_();
}