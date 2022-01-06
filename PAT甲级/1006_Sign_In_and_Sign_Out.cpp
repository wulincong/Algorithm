#include <iostream>
#include <string>

using namespace std;

class Time{
    private:
        int hours, minutes, seconds;
    public:
        Time(int h, int m, int s){
            hours = h;
            minutes = m;
            seconds = s;
        }
        bool operator==(const Time & t) const{
            return hours == t.hours && minutes == t.minutes && seconds == t.seconds;
        }
        bool operator>(const Time & t) const{
            if(hours > t.hours) return true;
            else if(hours < t.minutes) return false;
            else{
                if(minutes > t.minutes) return true;
                else if(minutes < t.minutes) return false;
                else{
                    if(seconds > t.seconds) return true;
                    else if(seconds < t.seconds) return false;
                    else return false;
                }
            }
        }
        bool operator<(const Time & t) const{
            return ! (*this > t) && ! (*this == t);
        }
        void Show() const{
            printf("%02d:%02d:%02d", hours, minutes, seconds);
        }
};


class Person{
    private:
        string ID;
        Time signing, signout;
};

int main(int argc, char *argv[]){
    int M;
    cin >> M;
    for(int i = 0; i < M; i++){
        string ID;
        cin >> ID;
        
    }
}

