/* 读入一个正整数 n，计算其各位数字之和，用汉语拼音写出和的每一位数字。
* 
* 输入格式：
* 每个测试输入包含 1 个测试用例，即给出自然数 n 的值。这里保证 n 小于 10^100
* 
* 输出格式：
* 在一行内输出 n 的各位数字之和的每一位，拼音数字间有 1 空格，但一行中最后一
* 个拼音数字后没有空格。
*/

#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main(int argc, char **argv){
    string s;       //接收输入
    char buffer[100];
    vector<string> PinYin(10);
    PinYin = {
        "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"
    };
    char *pBuffer = buffer;
    cin >> s;
    
    int Sum = 0;
    for(auto i : s){
        Sum = Sum + i - '0';
    }
    snprintf(buffer,100, "%d", Sum);
    while (*pBuffer != '\0'){
        cout << PinYin[*pBuffer - '0'];
        pBuffer ++;
        if(*pBuffer != '\0') cout << " ";
    }
    cout << endl;
    return 0;
}


