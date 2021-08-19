#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

typedef struct GNode_{
    string name;
    int weight;
    vector<int> Adj;
    vector<int> routeWeights;
} * GNode;

vector<GNode> G;
map<string, int> name_map;

int main(int argc, char **argv){
    int N, K, weight;
    cin >> N >> K;
    string name1, name2;
    for (int i = 0; i < N; i++){
        cin >> name1 >> name2 >> weight;
        
    }
}