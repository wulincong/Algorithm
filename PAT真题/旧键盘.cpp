#include <iostream>
#include <cctype>

using namespace std;

int main(int argc, char **argv){
    string s1, s2, ans; //
    cin >> s1 >> s2;
    for (auto i: s1){
        if(s2.find(i) == string::npos && ans.find(toupper(i)) == string::npos)
            ans += toupper(i);
    }
    cout << ans << endl;
    return 0;
}