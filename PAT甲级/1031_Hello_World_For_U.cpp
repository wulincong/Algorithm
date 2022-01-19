#include <iostream>
#include <string>
#include <vector>
using namespace std;


/* 分析：如果(N+2)整除3，那么是最好的，
n1 n3的值要一个个试，满足n2>=n1,最高不会超过N/2，最低是3
*/

int main(int argc, char* argv[]){
    string str;
    int n1, n2, n3;
    cin >> str;
    int N = str.size();
    //确定n1 n3的值
    for(int i = 3; i < N/2; i++) {
        n1 = i, n3 = i;
        n2 = N + 2 - n1 - n3;
        if(n2 < n1) break;
    }  
    n2 = N + 2 - n1 - n3;
    // cout << n1 << " " << n2 << " " << n3 << endl;
    int k = n2 - 2;//前n1-1行要填充的空格数
    for(int i = 0; i < n1 - 1; i++){
        cout << str[i];
        for(int j = 0; j < k; j++) cout << " ";
        cout << str[N - i - 1]<< endl;
    }
    for(int i = n1 - 1; i < n1 + n2 - 1; i++){
        cout << str[i];
    }
    cout << endl;
    return 0;
}





