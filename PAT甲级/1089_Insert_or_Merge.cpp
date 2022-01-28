#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const bool is_insert = true;
const bool is_merge = false;

bool compare(const vector<int> & A, const vector<int> & B){
    for(int i = 0; i < A.size(); i++){
        if(A[i] != B[i]) return false;
    }
    return true;
}

void insertSortOne(vector<int> &A, int n){
    for(int i = n; i > 0; i--){
        if(A[i] < A[i-1]) swap(A[i], A[i-1]);
        else return;
    }
}

void mergeSortOne(vector<int> &A, int n){
    int i = 1;
    while(i * n < A.size()){
        sort(A.begin() + A[(i - 1) * n], A.begin() + (i * n < A.size() ? A[i * n] : A.size()));
        i++;
    }
}

int main(){
    int N;
    cin >> N;
    bool flag = is_insert;
    vector<int> Array_A(N), Array_B(N);
    for(int i = 0; i < N; i++) cin >> Array_A[i];
    for(int i = 0; i < N; i++) cin >> Array_B[i];

    for(int i = 1; i < N / 2; i *= 2){
        mergeSortOne(Array_A, i);
        if(compare(Array_A, Array_B)){
            flag = is_merge;
            mergeSortOne(Array_A, i);
            break;
        }
    }
    if(flag == is_merge){
        cout << "Merge Sort" << endl;
        for(int i = 0; i < N; i++){
            cout << Array_A[i];
            if(i != N-1) cout << " ";
        }
    }else{
        for(int i = 1; i < N; i++){
            insertSortOne(Array_A, i);
            if(compare(Array_A, Array_B)){
                flag = is_merge;
                insertSortOne(Array_A, i + 1);
                break;
            }
        }
        cout << "Insertion Sort" << endl;
        for(int i = 0; i < N; i++){
            cout << Array_A[i];
            if(i != N-1) cout << " ";
    }
    }
}
