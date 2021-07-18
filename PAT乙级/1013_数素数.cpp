#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int x){
    for (int i = 2; i * i <= x; i++){
        if(x % i == 0){ return false; }
    }
    return true;
}

int main(int argc, char **argv){
    int M, N, num = 2, cnt = 0;
    vector<int> primes;
    cin >> M >> N ;
    while(cnt < N){
        if(isPrime(num)){
            cnt++;
            if(cnt >= M) primes.push_back(num);
        }
        num++;
    }
    cnt = 0;
    for(int i = 0; i < primes.size(); i++){
        cnt++;
        if(cnt % 10 != 1) printf(" ");
        printf("%d", primes[i]);
        if(cnt % 10 == 0) printf("\n");
    }
    return 0;
}