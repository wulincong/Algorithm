#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(int argc, char **argv){
    vector<int> V(100000, -1);
    vector<char> Exist(100000, 0);
    set<int> dogs;
    int N, M;
    int P1, P2;
    cin >> N;
    while(N){
        cin >> P1 >> P2;
        V[P1] = P2;
        V[P2] = P1;
        N--;
    }
    cin >> M;
    while(M){
        cin >> P1; 
        Exist[P1] = 1;
        M--;
    }
    for(int i = 0; i < 100000; i++){
        if(Exist[i]){
            if(V[i] == -1 || !Exist[V[i]])
                dogs.insert(i);
        }
    }
    cout << dogs.size() << endl;
    for(auto it = dogs.begin(); it != dogs.end(); it++){
        if(it != dogs.begin())
            cout << " ";
        cout << *it;
    }
}