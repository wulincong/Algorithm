#include <iostream>
using namespace std;

int main(int argc, char *argv[]){
    long long n,m,count = 0;;
    double sum = 0.0;
    while(scanf("%d %d",&n,&m)){
        count++;
        if(n>m || (n == 0 && m == 0)){
            cout << "Case" << count << ": " << "GG" << endl;
            return 0;}
        for(long long i = n; i <= m; i++)
            sum += 1.0/(double)n/n;
        printf("Case %d: %.5lf\n",count,sum);
    }
}
