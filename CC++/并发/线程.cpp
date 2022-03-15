#include <thread>
#include <iostream>
using namespace std;

void f(){
    cout << "1";cout << "2";cout << "3";cout << "4";    
    };
struct F{
    void operator()(){cout << "5"; cout << "6"; cout << "7"; cout << "8";};
};

void use(){
    thread t1 {f};   //f()在独立的线程中
    thread t2 {F()}; //F()()
    t1.join();  //等待t1完成
    t2.join();  //等待t2完成
}

int main(){
    use();
}