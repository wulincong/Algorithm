#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<int, int> Map;

void AddColor(int color){
    if(Map.count(color)) Map[color]++;
    else Map[color] = 1;
}

int main(int argc, char** argv){
    int M, N, t, max = 0;
    cin >> M >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> t;
            AddColor(t);
        }
    }

    for(map<int, int>::iterator i = Map.begin(); i != Map.end(); i++){
        if (i->second > max)t = i->first;
    }
    cout << t << endl;
}