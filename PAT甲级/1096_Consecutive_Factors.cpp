#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char **argv){
    int N;
    cin >> N;
    vector<int> Fact_n(14, 1);
    for(int i = 2; i < 13; i++) Fact_n[i] = Fact_n[i-1] * i;
    int n = 1;
    while(Fact_n[n++] < N);
    for(int i = n - 1; i >= 1; i--){
        int fact = 1;
        for(int j = 2; j < 13 - i && fact < N; j++){
            fact = Fact_n[j + i] / Fact_n[j];
            int w = N % fact;
            if(w == 0){
                cout << i << endl;
                for(int o = j + 1; o <= j+i; o++){
                    cout << o;
                    if(o != j + i) cout << "*";
                }
                return 0;
            }
        }
    }
}



