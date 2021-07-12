#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(int argc, char **argv){
    string all = "+-.,_0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    vector<int> isgood(68, 1);
    string bad, str;
    cin >> bad;
    cin >> str;
    for(auto i: bad) {
        // cout<<i<<endl;
        if(i == '+'){
            isgood[all.find("+")] = 0;
            for(char c = 'A'; c <= 'Z'; c++)isgood[all.find(c)] = 0;
        }
        else{
            isgood[all.find(i)] = 0;
            isgood[all.find(tolower(i))] = 0;
        }
    }
    for(auto i:str){
        if(isgood[all.find(i)] == 1) cout << i;
    }
    cout << endl;

}