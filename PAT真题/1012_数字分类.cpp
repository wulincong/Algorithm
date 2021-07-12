/*
* A​1 = 能被 5 整除的数字中所有偶数的和；
* A2 = 将被 5 除后余 1 的数字按给出顺序进行交错求和，即计算 n1−n2+n3−n​4 ⋯；
* A3 = 被 5 除后余 2 的数字的个数；
* A4 = 被 5 除后余 3 的数字的平均数，精确到小数点后 1 位；
* A5 = 被 5 除后余 4 的数字中最大数字。
*/
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main(int argc, char **argv){
    int N;
    cin >> N;
    int A1 = 0, A2 = 0, A3 = 0,  A5 = 0 , T;
    float A4 = 0.0;
    int flag_A2 = 1, cnt_A4 = 0;
    bool isExist_A1 = false, isExist_A2 = false, isExist_A3 = false,\
     isExist_A4 = false, isExist_A5 = false;
    while(N){
        cin >> T;
        // A​1 = 能被 5 整除的数字中所有偶数的和；
        if(T % 5 == 0 && T % 2 == 0) {A1 += T;isExist_A1 = true;}
        // A2 = 将被 5 除后余 1 的数字按给出顺序进行交错求和，即计算 n1- n2+ n3..
        if(T % 5 == 1) {A2 += flag_A2 * T;flag_A2 *= -1; isExist_A2 = true;}
        // A3 = 被 5 除后余 2 的数字的个数；
        if(T % 5 == 2) {A3++;  isExist_A3 = true;}
        // A4 = 被 5 除后余 3 的数字的平均数，精确到小数点后 1 位；
        if(T % 5 == 3){
            A4 += T;
            cnt_A4++;
            isExist_A4 = true;
        }
        // A5 = 被5除后余 4 的数字中最大数字。
        if(T % 5 == 4 ){
            if(T > A5) A5 = T;
            isExist_A5 = true;
        }
        N--;
    }
    A4 = A4 / cnt_A4;
    T = (A4 + 0.05) * 10;
    A4 = T / 10.0;
    char A4_buffer[10];
    snprintf(A4_buffer, 10, "%.1lf", A4);
    isExist_A1 ? cout << A1 << " ": cout << "N ";
    isExist_A2 ? cout << A2 << " ": cout << "N ";
    isExist_A3 ? cout << A3 << " ": cout << "N ";
    isExist_A4 ? cout << A4_buffer << " ": cout << "N ";
    isExist_A5 ? cout << A5: cout << "N";
}