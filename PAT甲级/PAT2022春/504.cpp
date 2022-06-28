#include <string>
#include <algorithm>
using namespace std;

class Solution{
public:
    string convertToBase7(int num){
        if(num == 0) return "0";
        bool negative = num < 0;
        num = abs(num);
        string digits;
        while(num > 0){
            digits.push_back('0' + num % 7);
            num /= 7;
        }
        if(negative) digits.push_back('-');
        reverse(digits.begin(), digits.end());
        return digits;
    }
};