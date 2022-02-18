#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char **argv){
    int N;
    cin >> N;
    vector<int> numbers;
    for(int i = 0; i < N; i++){
        int t;cin >> t;
        numbers.push_back(t);
    }
    sort(numbers.begin(), numbers.end());
    for(int i = 1; i < N; i++){
        if(! binary_search(numbers.begin(), numbers.end(), i)){
            cout << i;
            break;
        }
    }
}