//#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main(int argc, char **argv){
    vector<int> Array(10000,-1);
    int n;
    cin >> n;
    int inputs[n];
    map<int, int> roots;
    for (int i = 0; i < n; i++){
        cin >> inputs[i];
        roots[inputs[i]] = 1;
    }
    for (int i = 0; i < n; i++){
        int t = inputs[i];
        while (t != 1){
            if(Array[t] != -1){ //如果已经遍历过这个节点
                roots[t] = 0;
                break;
            }
            else{
                int next;
                if(t % 2 == 0){
                    // cout << t << "偶数\n"; 
                    next = t/2;
                    Array[t] = next;
                    t = next;
                    if(roots.find(t) != roots.end()) {
                        // cout << "t = "<< t << " " << roots[t] <<"之前的 \n";
                        roots[t] = 0; 
                        // cout << "t = "<< t << " " << roots[t] <<"之后的 \n";
                        }
                }
                else{
                    // cout << t << "奇数\n"; 
                    next = (t * 3 + 1) / 2;
                    Array[t] = next;
                    t = next;
                    if(roots.find(t) != roots.end()) {
                        // cout << "t = "<< t << " " << roots[t] <<"之前的 \n";
                        roots[t] = 0; 
                        // cout << "t = "<< t << " " << roots[t] <<"之后的 \n";
                        }
                }
            }
        }
    }
    auto iter = roots.begin();
    set<int> S;
    while(iter != roots.end()){
        if(iter->second == 1){
            // cout << iter->first << endl;
            S.insert(iter->first);
        } 
        iter++;
    }
    auto i = S.end();
    for(--i; i != S.begin(); i--){
        cout << *i << " ";
        // if(i != S.begin()) cout << " ";
    }
    cout << *S.begin();

}