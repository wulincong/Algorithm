#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class RichPeople{
public:
    int age, net_worths;
    string name;
    RichPeople(string, int, int);
};

RichPeople::RichPeople(string n, int a, int w):
name(n), age(a), net_worths(w)
{}

bool cmp(RichPeople & a, RichPeople & b){
    if(a.net_worths == b.net_worths && a.age == b.age) return a.name < b.name;
    else if(a.net_worths == b.net_worths) return a.age < b.age;
    else return a.net_worths > b.net_worths;
}

vector<RichPeople> peoples;

void query(int M, int Amin, int Amax){
    int cnt = 0;
    vector<RichPeople>::iterator it = peoples.begin();
    while(cnt < M && it != peoples.end()){
        if(it->age >= Amin && it->age <= Amax){
            cnt++;
            cout << it->name << " "
                << it->age << " "
                << it->net_worths << endl;
        }
        it++;
    }
    if(cnt == 0) cout << "None" << endl;
}

int main(){
    int N, K;
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        string name;
        int age, net_worths;
        cin >> name >> age >> net_worths;
        peoples.push_back(RichPeople(name, age, net_worths));
    }
    sort(peoples.begin(), peoples.end(), cmp);
    for(int i = 1; i <= K; i++){
        cout << "Case #" << i << ":" << endl;
        int M, Amin, Amax;
        cin >> M >> Amin >> Amax;
        query(M, Amin, Amax);
    }
}