#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

map<int, vector<int> > Courses;   //从course_id 到 student_id的映射
vector<string> Students;

void AddStudent(int course_id, int student_id){
    if(! Courses.count(course_id)){
        Courses[course_id] = vector<int>();  //没有则创建之
    }
    Courses[course_id].push_back(student_id);
}

int main(int argc, char **argv){
    int N, K, t;
    cin >> N >> K;
    for(int i=0; i<N; i++){
        string s, name;
        getline(cin, s);
        stringstream ss(s);
        ss >> name >> t;
        int student_id = Students.size();
        Students.push_back(name);
        while(ss >> t) AddStudent(t, student_id);
    }
    for(map<int, vector<int> >::iterator iter = Courses.begin(); iter != Courses.end(); iter++){
        cout << iter->first << " " << iter->second.size() << endl;
        sort(iter->second.begin(), iter->second.end());
        for(int i : iter->second){
            cout << Students[i] << endl;
        }
    }
}



