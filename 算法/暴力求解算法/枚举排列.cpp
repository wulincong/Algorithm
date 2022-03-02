#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void print_permutation(int n, int * A, int cur){
    if(cur == n){     
        for(int i = 0; i < n; i++)std::cout << A[i] << " ";
        std::cout << std::endl;
    }
    else for(int i = 1; i <= n; i++){   // 尝试在A[cur]中填数据
        int ok = 1;
        for(int j = 0; j < cur; j++)
            if(A[j] == i) ok = 0;  // i已经出现过
        if(ok){
            A[cur] = i;
            print_permutation(n, A, cur + 1);
        }
    }
}


int A[10];
int main(int argc, char ** argv){
    print_permutation(4, A, 0);
    int n, p[10];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &p[i]);
    sort(p, p + n);
    do{
        for(int i = 0; i < n; i++) printf("%d ", p[i]); //输出排列p
        printf("\n");
    }while (next_permutation(p, p + n));
    return 0;    
}