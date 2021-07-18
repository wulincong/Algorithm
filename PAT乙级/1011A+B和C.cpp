#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char **argv){
    int T;
    long long A, B, C;
    cin >> T;
    vector<bool> isBigger(T+1, false);
    for(int i = 1; i <= T; i++){
        cin >> A >> B >> C ;
        if(A + B > C) isBigger[i] = true;
    }
    for(int i = 1; i <= T; i++){
        cout << "Case "
             << "#" << i << ": ";
        isBigger[i] ? cout <<"true\n" : cout << "false\n";
    }

}