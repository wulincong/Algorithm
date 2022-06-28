/*
the string starts with an f has its score −2;

the string ends with an a has its score −1;

for every longest segment of answeres where the same letter is chosen for 
consecutive questions, if the segment length is larger than 5, the score is to +3;连续相同的字符

if an a is immediately followed by e or h, the score is to −4; a接e或h

for every longest segment of answeres where consecutively increasing letters are 
chosen to answer consecutive questions (such as abcd or defgh), if the segment 
length is larger than 3, the score is to +5.  递增序列

12 1 6
fghaebcdeddd
ahhhhhhgbaaa
cdefffffffff
fffffghecaaa
feeeeeeeegcb
aaaaaabbbbbb
abcdabcdabcd

-1
-2
8!!!
-3
1
6!!!

*/

#include <iostream>
#include <string>
#include <map>
using namespace std;

int find_segment(string s, int & n){
    char a = s[0];
    int cnt = 0;
    map<char, int> M;
    for(auto it = s.begin(); it != s.end(); it++){
        if(*it == a) cnt++;
        else {
            if(!M.count(*it)) M[a] = cnt;
            else if(M.count(*it) && M[*it] < cnt) M[a] = cnt;
            cnt = 1;
            a = *it;
        }
        if(it + 1 == s.end()){
            if(!M.count(*it)) M[*it] = cnt;
            else if(M.count(*it) && M[*it] < cnt) M[*it] = cnt;
        }
    }
    // cout << M.size() << endl;
    int maxit = 0;
    for(auto it:M) if(it.second > maxit) maxit = it.second;
    n = 0;
    for(auto it:M) if(it.second == maxit) n++;
    return maxit;

}

int main(){
    int N, T, K;
    cin >> N >> T >> K;
    for(int i = 0; i < K; i++){
        string question;
        cin >> question;
        int score = 0;
        if(question[0] == 'f') score += -2;
        if(question[N - 1] == 'a')score += -1;
        int n;
        if(find_segment(question, n) > 5) score += 3 * n;
        // cout << "n = " << n << endl;
        for(int i = 0; i < N; i++){
            if(question[i] == 'a' && i+1 < N && question[i+1] == 'e') score -= 4;
            if(question[i] == 'a' && i+1 < N && question[i+1] == 'h') score -= 4;

        }
        int cnt_of_increase = 1;
        int max_increase = 0;
        int cnt = 0;
        for(int i = 0; i < N - 1; i++){
            if(question[i] + 1 == question[i+1]) cnt_of_increase +=1;
            else {
                if(cnt_of_increase > 3) max_increase++;
                cnt_of_increase = 1;
            }
        }
        if(cnt_of_increase > 3) max_increase++;
        // cout << max_increase << endl;
        score += 5 * max_increase;
        if(score > T) cout << score << "!!!" << endl;
        else cout << score << endl;
        
    }
}