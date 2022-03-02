#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

struct Vertex{
    int weight = 0;
    string name;
    vector<int> neibors;
    Vertex(string n):name{n}{}
};

vector<Vertex> Persons;
map<string, int> Names;
int vis[1009];

int N, K;

bool addName(string name, int idx){
    if(Names.count(name)) return false;
    Names[name] = idx;
    return true;
}



void dfs(int idx,int id){
    vis[idx] = id;
    for(auto i: Persons[idx].neibors){
        if(! vis[i]) dfs(i, id);
    }
}

int count(int id, int & w){
    int cnt = 0;
    for(int i = 0; i < Persons.size(); i++){
        if(vis[i] == id) {
            cnt++;
            w += Persons[i].weight;
        }
    }
    w = w/2;
    return cnt;
}

void findHead(int id){
    int max = 0, cnt = 0;
    string max_name;
    for(int i = 0; i < Persons.size(); i++){
        if(vis[i] == id){
            cnt++;
            if(Persons[i].weight > max){
                max = Persons[i].weight;
                max_name = Persons[i].name;
            }
        } 
    }
    cout << max_name << " " << cnt << endl;
}

int main(){
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        string n1, n2;
        int t;
        cin >> n1 >> n2 >> t;
        if(! Names.count(n1)){
            Persons.push_back(Vertex(n1));
            addName(n1, Persons.size() - 1);
        } 
        if(! Names.count(n2)){
            Persons.push_back(Vertex(n2));
            addName(n2, Persons.size() - 1);
        }
        Vertex * P1 = &Persons[Names[n1]];
        Vertex * P2 = &Persons[Names[n2]];
        P1->neibors.push_back(Names[n2]);
        P2->neibors.push_back(Names[n1]); 
        P1->weight += t; P2->weight += t;       
    }
    int id = 1;
    for(int i = 0; i < N; i++){
        if(!vis[i]){
            dfs(i, id);
            id++;
        } 
    }
    // cout << id - 1;
    vector<int> Gang;
    for(int i = 1; i < id; i++){
        int w = 0;
        if(count(i, w)>2 && w > K) Gang.push_back(i);
    }
    cout << Gang.size() << endl;
    for(int id:Gang){
        findHead(id);
    }
}
