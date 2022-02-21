#include <iostream>
#include <cstring>
using namespace std;

/*
在枚举子集的增量法中， 需要使用定序的技巧， 避免同一个集合枚举两次。
*/
namespace Increase{
    void print_subset(int n, int *A, int curr){
        for(int i = 0; i < curr; i++)cout << A[i] << " ";
        cout << endl;
        int s = curr ? A[curr - 1] + 1 : 0;   //如果curr > 0 则选择
        for(int i = s; i < n; i++){
            A[curr] = i;
            print_subset(n, A, curr+ 1);
        }
    }
}
/*向量法*/
namespace Vector{
    void print_subset(int n, int *B, int curr){
        if(n == curr){
            for(int i = 0; i < curr; i++){
                if(B[i]) cout << i << " ";
            }cout << endl;
            return;
        }
        B[curr] = 1;
        print_subset(n, B, curr+1);
        B[curr] = 0;
        print_subset(n, B, curr+1);
    }
}

/*二进制法*/
void print_subset(int n, int s){
    for(int i = 0; i < n; i++)
        if(s & (1 << i)) cout << i << " ";
    cout << endl;
}

int main(int argc, char *argv[]){
    int A[11];
    int n = 10;
    Increase::print_subset(n, A, 0);
    memset(A, 0, sizeof(A));     
    Vector::print_subset(n, A, 0);   
    for(int i = 0; i < (1<<n); i++)
        print_subset(n, i);
}

