#include <stdio.h>
#include <time.h>
#include "Yutils.h"

double timeIt( void f() , size_t times){
    clock_t start, stop;
    double duration;
    start = clock();
    while(times--)
        f();
    stop = clock();
    duration = ((double)(stop - start)) / CLK_TCK;
    return duration;
}
