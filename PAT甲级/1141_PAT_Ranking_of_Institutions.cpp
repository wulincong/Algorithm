#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Institution{
    string school;
    float TWS = 0.0;
    int Ns = 0;
    Institution(string s):school(s){}
};
map<string, Institution> Map;

void Add(string school, char level, int score){
    if(! Map.count(school)) {
        Map[school] = Institution(school);
    }
    Map[school].Ns++;
    if(level == 'B') Map[school].TWS += score/1.5;
    else if(level == 'A') Map[school].TWS += score;
    else if(level == 'T') Map[school].TWS += score*1.5;
};

bool cmp(Institution &A, Institution &B){
    if(A.TWS == B.TWS && A.Ns == B.Ns) return A.school < B.school;
    if(A.TWS == B.TWS) return A.Ns < B.Ns;
    return A.TWS < B.TWS;
};

int main(){
    int N, score;
    cin >>N;
    string ID, school;
    for(int i=0; i < N; i++){
        cin >> ID >> score >> school;
        transform(school.begin(), school.end(), school.begin(), ::tolower);
        Add(school, ID[0], score);
    }
    vector<Institution> V;
    for(map<string, Institution>::iterator it = Map.begin(); it != Map.end(); it++){
        V.push_back(it->second);
    }
    sort(V.begin(), V.end(), cmp);
    cout << Map.size() << endl;
    int rank = 1, lastTWS= V[0].TWS;
    for(int i = 0; i < V.size(); i++){
        if(! V[i].TWS == lastTWS){
            rank = i + 1;
        }
        cout << rank << " "
            << V[i].school << " "
            << V[i].TWS << " "
            << V[i].Ns << endl;       
        lastTWS = V[i].TWS;
    }
}

