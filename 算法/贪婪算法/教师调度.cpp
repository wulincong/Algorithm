#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;
bool isEnd(float c_t, map<string, vector<float>> m){
    for(auto i:m ) {
        if(i.second[0] >= c_t) return true;
    }
    return false;
}

int main(int argc, char **argv){
    map<string, vector<float>> m = {
        {"美术", {9, 10}},
        {"英语", {9.5, 10.5}},
        {"数学", {10, 11}},
        {"计算机", {10.5, 11.5}},
        {"音乐", {11, 12}},
    };
    float current_time = 9;   // current time = min begin time
    float end_time = 12;
    while (isEnd(current_time, m)){
        
        for(auto i: m){
            //find the min end time from current_time
            

        }

    }
}