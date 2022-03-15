#include <iostream>
using namespace std;
 
int main(int argc, char** argv) {
    unsigned int value = 1024;
    bool condition = *((bool*)(&value));
    if (condition) value += 1; condition = *((bool*)(&value));
    if (condition) value += 1; condition = *((bool*)(&value));
    cout << value << endl;
    cout << condition << endl;
}