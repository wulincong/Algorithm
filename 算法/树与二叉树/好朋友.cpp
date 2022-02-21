#include <iostream>
using namespace std;
int father[100];

int findFather(int x ){
    if(x == father[x]) return x;
    else{
        return findFather(father[x]);
    }
}

int main(){
    int N, Lines, a, b;
    cin >> N >> Lines;
    for(int i=0; i<100; i++)father[i] = 0;
    for(int i = 0; i < Lines; i++){
        cin >> a >> b;
        if(father[a] == 0 && father[b] == 0){
        //a b 同时都没朋友
            father[a] = a;
            father[b] = a;
        }
        if(findFather(a) != 0) father[b] = findFather(a); //a 有朋友
        else if(findFather(b) != 0)father[a] = findFather(b);  // b 有朋友
    }
    int cnt = 0;
    for(int i = 1; i <= N; i++){
        // cout << father[i]<< " ";
        if(father[i] == i || father[i] == 0)cnt++;
    }
    cout << "\n" << cnt << endl;
}






