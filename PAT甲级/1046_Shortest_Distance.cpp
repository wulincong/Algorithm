#include <iostream>
#include <vector>
using namespace std;

int Sum(const vector<int> & V, int b, int e){
    int sum = 0;
    if(b == e) return sum;
    if(b < e){
        for(int i = b; i < e; i++){
            sum += V[i];
        }
        return sum;
    }else{
        for(int i = b; i <= V.size();i++) sum += V[i];
        for(int i = 1; i < e; i++) sum += V[i];
        return sum;
    }
}

int main(){
    int N;
    cin >> N;
    vector<int> V(N+1);
    for(int i = 1; i <= N; i++) {
        int tmp; cin >> tmp;
        V[i] = tmp;
    }
    int M; cin >> M;
    for(int i = 0; i < M; i++){
        int b, e;
        cin >> b >> e;
        int s1 = Sum(V, b, e), s2 = Sum(V, e, b);
        cout << (s1 < s2 ? s1 : s2) << endl;
    }
}