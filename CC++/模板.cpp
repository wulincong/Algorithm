


template <typename T>
void mySwap(T &a, T &b){
    T tmp = a;
    a = b;
    b = tmp;
}

int main(){
    //自动类型推导
    int a = 1, b = 2;
    mySwap(a, b);
    //显示指定类型
    mySwap<int>(a, b);
    
}
