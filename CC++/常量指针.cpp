#include <iostream>

int main(int argc, char **argv){
    int a = 1, b = 2;
    const int * p = &a;
    class Func{
        void Print(){
            std::cout << "111" << std::endl;
        }
        void operator()(){
            std::cout << "111" << std::endl;
        }
    };
    Func *F = NULL;
    
}
