#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>

using namespace std;

const int maxn = 2e5;
int prime[maxn];
int fac_cnt[maxn];
vector<int> primes;

void find_prime(){
    memset(prime, 1, sizeof(prime));
    for(int i = 2; i < maxn / 2; i++)if(prime[i])
        for(int j = 2; j * i < maxn; j++) prime[i * j] = 0;
}

bool is_prime(int n){
    if(n < 2) return false;
    for(int i = 2; i < n / i; i++){
        if(n % i == 0) return false;
    }
    return true;
}


void divide(int n){
    memset(fac_cnt, 0, sizeof(fac_cnt));
    int sqr = (int)sqrt(n);
    for(int i:primes){
        if(i > sqr) break;
        while(n % i == 0){
            fac_cnt[i]++;
            n /= i;
        }
    }
    if(n > sqr) fac_cnt[n]++;
}

int main(){
    int n;
    find_prime();
    for(int i = 2; i < maxn; i++) if(prime[i]){
        primes.push_back(i);
    } 
    while(cin >> n) {
        if(prime[n]) cout << n << " is prime" << endl;
        else {
            divide(n);
            for(int i = 2; i < maxn; i++)if(fac_cnt[i]){
                cout << i << "^" << fac_cnt[i] << " * ";
            }
            cout << endl;
        }
    }
}