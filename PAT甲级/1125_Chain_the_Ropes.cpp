#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<double> V(N);    
    string s;
    getline(std::cin, s);
    getline(std::cin, s);
    stringstream ss(s);
    int i = 0; while(ss >> V[i])i++;
    sort(V.begin(), V.end());
    double cnt = *V.begin();
    cout << "ok" << endl;
    for(int i=1; i<N; i++){
        cnt = (cnt + V[i]) / 2;
    }
    cout << (int)cnt << endl;
}