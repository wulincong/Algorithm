#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char **argv){
    int N1, N2;
    cin >> N1;
    vector<int> V1(N1);
    for(int i = 0; i < N1; i++){ cin >> V1[i];}
    cin >> N2;
    vector<int> V2(N2);
    for(int i = 0; i < N2; i++){ cin >> V2[i];}
    vector<int>::iterator p1 = V1.begin();
    vector<int>::iterator p2 = V2.begin();
    int cnt = 0;
    int res = (N1 + N2) % 2 == 0 ? (N1 + N2) / 2 - 1 : (N1 + N2 + 1) / 2 - 1;
    while(cnt != res){
        if(*p1 < *p2) p1++;
        else p2++;
        cnt++;
    }
    *p1 < *p2 ? cout << *p1 : cout << *p2;
}



