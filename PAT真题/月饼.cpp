#include <bits/stdc++.h>
using namespace std;
vector<float> inStocks, totalSellingPrices, unitPrices;

bool cmp(int a, int b){
        return unitPrices[a] > unitPrices[b];
}
int main(int argc, char **argv){
    int N, D;
    float T;
    cin >> N >> D ;
    vector<int> SortOrder;
    for(int i = 0; i < N; i++){
        SortOrder.push_back(i);
        cin >> T;
        inStocks.push_back(T);
        }
    for (size_t i = 0; i < N; i++)
    {
        cin >> T;
        totalSellingPrices.push_back(T);
        unitPrices.push_back(T / inStocks[i]);
    }
    sort(SortOrder.begin(), SortOrder.end(),cmp);
    // for(auto i : unitPrices) cout << i << " "; cout << endl;
    T = 0;
    for(auto i : SortOrder){ 
        if(inStocks[i] <= D){
            D -= inStocks[i];
            T += totalSellingPrices[i];
        }
        else{
            T += unitPrices[i] * D;
            D = 0;
        }

    }
    T = round(T * 100) / 100;
    printf("%.2f", T);
}