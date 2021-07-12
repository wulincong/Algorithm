#include <iostream>
#include <string>
using namespace std;

int main(int argc, char **argv){
    string namet,maxName,minName;
    string idt,maxId,minId;
    int Scoret, minScore = 100, maxScore = 0, n;
    cin >> n;
    while(n){
        cin >> namet >> idt >> Scoret;
        if(Scoret > maxScore) {
            maxScore = Scoret;
            maxName = namet;
            maxId = idt;
        }
        if(Scoret < minScore) {
            minScore = Scoret;
            minName = namet;
            minId = idt;
        }
        n--;
    }
    cout << maxName << " " << maxId << endl;
    cout << minName << " " << minId << endl;
    return 0;

}
