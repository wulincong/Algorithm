#include <iostream>

using namespace std;

int main(int argc, char **argv){
    int a,b,c,t;
    int Galleon, Sickle, Kunt;
    scanf("%d.%d.%d",&Galleon,&Sickle,&Kunt);
    scanf("%d.%d.%d",&a,&b,&c);
    Galleon += a; Sickle += b; Kunt += c;
    Sickle += Kunt / 29; Kunt = Kunt % 29;
    Galleon += Sickle / 17; Sickle = Sickle % 17;
    cout << Galleon << "." << Sickle << "." << Kunt;
}


