#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char **argv){
    vector<int> v(10);
    for(int i=0; i < 10; i++) cin >> v[i];
    int min = 10;
    for(int i = 9; i > 0; i--){
        if(v[i] != 0) min = i;
    }
    v[min] -= 1;
    cout << min;
    for(int i = 0; i < 10; i++){
        // cout << i;
        while(v[i] > 0){
            cout << i;
            v[i] -= 1;
        }
    }
    cout << endl;
    return 0;
}