#include <iostream>
#include <set>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

typedef set<int> Set;
vector<Set> V;

int main(int argc, char **argv){
    int N, K, t;
    cin >> N;
    V.push_back(set<int>());
    for(int i=1; i<=N; i++){
        set<int> sett;
        string s;
        getline(cin, s);
        stringstream ss(s);
        ss >> t;
        while(ss >> t){
            sett.insert(t);
        }
        V.push_back(sett);
    }
    cin >> K;
    for(int i=1; i<=N; i++){
        int a, b;
        float Nc, Nt;
        cin >> a >> b;
        set<int> res_j, res_u;
        set_intersection(V[a].begin(),V[a].end(), V[b].begin(), V[b].end(), res_j);
        Nc = res_j.size();
        set_union(V[a].begin(),V[a].end(),V[b].begin(), V[b].end(), res_u);
        Nt = res_u.size();
        printf("%.01f%\n", Nc / Nt * 100);
    }
}

