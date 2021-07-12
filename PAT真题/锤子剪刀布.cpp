#include <iostream>
#include <map>

#define JWIN 0
#define YWIN 1
#define DRAW 2

using namespace std;

int whoWin(char J, char Y){
    if (J == Y) return DRAW;
    if (J == 'J' && Y == 'B') return JWIN;
    else if (J == 'B' && Y == 'J') return YWIN;
    return J < Y ? JWIN : YWIN; 
}

int main(int argc, char **argv){
    int times, JiaWin = 0, YiiWin = 0;
    char J, Y;
    map<char, int> Jia = {{'C', 0},{'J', 0},{'B', 0}};
    map<char, int> Yii = {{'C', 0},{'J', 0},{'B', 0}};

    cin >> times;
    for (int i = 0; i < times; i++){
        cin >> J >> Y;
        // Jia[J]++;  //计算出的拳头种类数量
        // Yii[Y]++;
        int result = whoWin(J, Y);
        // cout << result << endl;
        
        if(result== 0) {JiaWin++; Jia[J]++; }
        else if (result == 1)  {YiiWin++; Yii[Y]++;}
    }
    cout << JiaWin << " " << times - JiaWin - YiiWin << " " << YiiWin << endl;
    cout << YiiWin << " " << times - JiaWin - YiiWin << " " << JiaWin << endl;
    char maxJ = 'B', maxY = 'B';
    if (Jia['C'] > Jia[maxJ]) maxJ = 'C';
    else if (Jia['J'] > Jia[maxJ]) maxJ = 'J';
    if (Yii['C'] > Yii[maxY]) maxY = 'C';
    else if (Yii['J'] > Yii[maxY]) maxY = 'J';
    cout << maxJ  << " " << maxY << endl;
    // cout << Jia['C'] << " " << Jia['B'] << " " << Jia['J'] << endl;
    return 0;
}