#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Student{
public:
    int ID, grade;
    string name;
    Student(int, string, int);
};

Student::Student(int id, string n, int g):
ID(id), name(n), grade(g)
{}

bool cmp1(Student& a, Student& b){
    return a.ID < b.ID;
}

bool cmp2(Student& a, Student& b){
    return a.name < b.name;
}

bool cmp3(Student& a, Student& b){
    return a.grade == b.grade ? a.ID < b.ID : a.grade < b.grade;
}

int main(int argc, char **argv){
    int N, C;
    vector<Student> students;
    cin >> N >> C;
    for(int i = 0; i < N; i++){
        int id, grade;
        string name;
        cin >> id >> name >> grade;
        students.push_back(Student(id, name, grade));
    }
    if(C == 1){
        sort(students.begin(), students.end(), cmp1);
    }else if(C==2){
        sort(students.begin(), students.end(), cmp2);
    }else{
        sort(students.begin(), students.end(), cmp3);
    }
    for(Student it : students){
        printf("%06d ", it.ID);
        cout << it.name << " "
            << it.grade
            << endl;
    }
}

