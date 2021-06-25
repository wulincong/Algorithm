#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]){
    for(int i = 100; i < 999; i++){
        if(pow(i % 10,3) + pow(i % 100 / 10, 3) + pow(i / 100, 3) == i){
            printf("%d\n",i);
        }
    }
}

