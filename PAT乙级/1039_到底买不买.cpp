#include <iostream> 
#include <map>
#include <string>
#include <vector>

using namespace std; //
bool findAndMark(string &S, char pattern, vector <bool> &Mark){
    bool Mark_success_flag = false;
    for(int i=0; i < S.size(); i++){
        if(S[i] == pattern && !Mark[i]) {
            Mark[i] = true;
            Mark_success_flag = true;
            return true;
        }
    }
    if(!Mark_success_flag) return false;
}
int main(int argc, char **argv){
    string S1, S2;
    cin >> S1 >> S2;
    int lengthS1 = S1.size();
    int lengthS2 = S2.size();
    vector<bool> Mark(lengthS1, false);
    int flag = 1;
    int cnt = 0;
    for(int i = 0 ; i < lengthS2; i++){
        if(! findAndMark(S1, S2[i], Mark)){
            flag = 0;
            cnt++;
        }
    }

    if(flag == 1) cout << "Yes " << S1.size() - S2.size() << endl;
    if(flag == 0) cout << "No " << cnt << endl;

}