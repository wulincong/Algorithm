#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const static char female = 'F';
const static char male = 'M';

class Student{
public:
    string name, ID;
    char gender;
    int grade;
    Student(string, string, char, int);
};

bool cmp(const Student& a, const Student& b){
    if(a.gender == female && b.gender == male) return true;
    else if(a.gender == male && b.gender == female) return false;
    else if(a.gender == male && b.gender == male){ // 都是男士按升序
        return a.grade > b.grade;
    }
    else return a.grade < b.grade;
}

Student::Student(string n, string id, char gen, int gra):
    name(n), gender(gen), grade(gra), ID(id) {}

int main(){
    int N;
    vector<Student> students;
    cin >> N;
    string n, id;
    char gen;
    int gra;
    for(int i=0; i<N; i++){
        cin >> n >> gen >> id >> gra;
        students.push_back(Student(n, id, gen, gra));
    }
    sort(students.begin(), students.end(), cmp);
    int flag = 0;
    if(students[0].gender == female) 
        cout << students[0].name << " " << students[0].ID << endl;
    else{
        cout << "Absent" << endl;
        flag = 1;
    }
    if(students[N - 1].gender == male)
        cout << students[N-1].name << " " << students[N-1].ID << endl;
    else{
        cout << "Absent" << endl;
        flag = 1;
    }
    if(!flag) cout << students[0].grade - students[N-1].grade << endl;
    else cout << "NA";
    return 0;
}
