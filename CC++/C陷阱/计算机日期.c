#include <stdio.h>
#include <time.h>

int main(int argc, char **argv){
    time_t max = 0x7FFFFFFFF;
    printf("%s", asctime(gmtime(&max)));
}