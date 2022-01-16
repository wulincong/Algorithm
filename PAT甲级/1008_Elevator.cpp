#include <iostream>

using namespace std;

int main(int argc, char **argv){
    int N, sum = 0, current_floor = 0, next_floor;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> next_floor;
        if(next_floor > current_floor){
            sum += 6 * (next_floor - current_floor);
        }
        else{
            sum += 4 * (current_floor - next_floor);
        }
        current_floor = next_floor;
        sum += 5;
    }
    cout << sum << endl;
}
