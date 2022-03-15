#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 2e6;
int prime[maxn];

void find_prime(){
    memset(prime, 1, sizeof(prime));    
    for(int i = 2; i < maxn; i++)if(prime[i]){
        for(int j = 2; j * i < maxn; j++) prime[j * i] = 0;
    }
}
int fac_cnt[maxn / 2];
void find_fac(long long x){
    long long sqr = sqrt(x);
    for(int i = 2; i < sqr; i++)if(prime[i]){
        while(x % i == 0){
            fac_cnt[i]++;
            x /= i;
        }
    }
    if(x > sqr) fac_cnt[x] = 1;
}

int main(int argc, char **argv){
    long long N;
    cin >> N;
    find_prime();
    find_fac(N);
    cout << N << "=";
    vector<int> facs;
    for(int i = 0; i < maxn/2;i++)if(fac_cnt[i])facs.push_back(i);
    for(int i = 0; i < facs.size();i++){
        if(fac_cnt[facs[i]] == 1) cout << facs[i];
        else cout << facs[i] << "^" << fac_cnt[facs[i]] ;
        if(i != facs.size() - 1) cout << "*";
    }

}