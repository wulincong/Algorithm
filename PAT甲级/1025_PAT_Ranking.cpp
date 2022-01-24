#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class testee{
public:
    long registration_number;
    int  final_rank, location_number, local_rank;
    int score;
    testee(long, int, int);
};

testee::testee(long reg, int sc, int loc):
registration_number(reg), score(sc), location_number(loc)
{}

bool cmp(testee & a, testee & b){
    if(a.score > b.score) return true;
    else if(a.score < b.score) return false;
    else{
        return a.registration_number  < b.registration_number;
    }
}

int main(){
    int N;
    int K;
    cin >> N;
    vector<testee> testees;
    vector<testee>::iterator it = testees.begin();
    for(int i = 1; i <= N; i++){
        cin >> K;
        for(int j = 0; j < K; j++){
            long id;
            int score;
            testees.push_back(testee(id, score, i));
        }
        sort(it, testees.end(),cmp);
        cout << "ss" << endl;
        int rank = 1;
        for(;it != testees.end();it++){
            it->local_rank = rank;
            rank++;
        }
        it++;
        for(; it != testees.end(); it++){
            if(it->score == --it->score) 
                it->local_rank = --it->local_rank;
        }
        it = testees.end();
    }
    sort(testees.begin(), testees.end(), cmp);
    int rank = 1;
    for(auto it:testees){
        it.final_rank = rank;
        rank++;
        if(it.registration_number != testees.front().registration_number && it.score == --it.score) 
            it.final_rank = --it.final_rank;
        cout << it.registration_number << " "<< it.final_rank << " "
            << it.location_number << " "
            << it.local_rank << endl;
    }
}








