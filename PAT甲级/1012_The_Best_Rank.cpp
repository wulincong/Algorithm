#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Student {
public:
    string ID;
    int A, M, E, C;
    Student(string id, int c, int m, int e){
        ID = id;
        C = c;
        M = m;
        E = e;
        A = (C + M + E) / 3;
    }
};

int main(int argc, char **argv){
    int N, M, c, m, e;
    string id;
    cin >> N >> M;
    vector<Student> students(N);
    vector<string> students_id(M);
    for(int i = 0; i < N; i++){
        cin >>id >> c >> m >> e;
        c,e,m;
        students.push_back(Student(id, c, m, e));
    }
    for(int i = 0; i < M; i++){
        cin >> students_id[i];
    }
    return 0;
}


