#include <iostream>
#include <vector>
using namespace std;

void printCard(int n){
    if(n >= 1 && n <= 13) cout << "S" << n;
    else if(n >= 14 && n <= 26) cout << "H" << n-13;
    else if(n >= 27 && n <= 39) cout << "C" << n-26;
    else if(n >= 40 && n <= 52) cout << "D" << n-39;
    else if(n == 53) cout << "J1";
    else if(n == 54) cout << "J2";
}

int main(){
    int K;
    cin >> K;
    vector<int> V;
    vector<int> result(55);

    for(int i = 0; i < 54; i++){
        int t;
        cin >> t;
        V.push_back(t);
    }
    for(int i = 1; i <= 54; i++){
        int curr = i;
        for(int k = 0; k < K; k++){
            result[V[curr]] = i;
            curr = V[curr];
        }
    }
    for(int i = 1; i <= 54; i++){
        // cout << result[i];
        printCard(result[i]);
        cout << " ";
    } 
}