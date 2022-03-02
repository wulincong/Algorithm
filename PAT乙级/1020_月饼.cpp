#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class mooncake{
public:
    double store, sell, price;
    mooncake(double store, double sell):store{store}, sell{sell}{
        price = sell / store;
    };
    bool operator<(const mooncake& other){
        return this->price > other.price;
    }
};

int N;
double D;
vector<mooncake> mooncakes;
int main(){
    cin >> N >> D;
    string s1, s2, tt;
    getline(cin, s1); 
    getline(cin, s1); 
    getline(cin, s2);
    cout << s1 << endl;
    cout << s2 << endl;
    stringstream ss1(s1); stringstream ss2(s2);
    for(int i = 0; i < N; i++){
        int t1, t2;
        ss1 >> t1; ss2 >> t2;
        mooncakes.push_back(mooncake(t1, t2));
    }
    sort(mooncakes.begin(), mooncakes.end());
    int idx = 0;
    double total = 0;
    while(D && idx < mooncakes.size()){
        if(D - mooncakes[idx].store > 0) {
            D -= mooncakes[idx].store;
            total += mooncakes[idx].sell;
        }else{
            total += mooncakes[idx].price * D;
            D = 0;
        }
        idx++;
    }
    printf("%.2f", total);
}