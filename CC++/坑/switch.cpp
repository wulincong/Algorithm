#include <iostream>
using namespace std;
int main()
{
    int x=3,y=3;
    switch(x%2)
    {
    case 1:
        switch (y)
        {
        case 0:
            cout<<"first";
        case 1:
            cout<<"second";
            break;
        default:
            cout<<"hello";
        }
    case 2:
        cout<<"third";
    }
    return 0;
}