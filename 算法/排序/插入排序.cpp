#include <iostream>
#include <vector>
using namespace std;
namespace point{
    void InsertSort(int *beg, int *end){
        for(int * i = beg; i != end; i++){
            int key = *i;
            int * j = i;
            while(j != beg && *j > key){
                j[1] = *j;
                j--;
            }
        }
    }
}

namespace Vector{
    void InsertSort(vector<int> V ){
        for(int i = 1; i < V.size(); i++){
            int key = V[i];
            int j = i;
            while(j > 0 && V[j] > key){
                V[j+1] = V[j];
                j--;
            }
        }
    }
}

int main() {
    int A[] = { 5, 4, 3, 2, 1};
    vector<int> V = { 5, 4, 3, 2, 1};
    point::InsertSort(A, A+5);
    for(int i = 0; i < 5; i++) cout << A[i] << endl;
    Vector::InsertSort(V);
    for(int i = 0; i < 5; i++) cout << V[i] << endl;
    return 0;
}
