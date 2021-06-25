#include <stdio.h>
#include <stdlib.h>

/*
 *  假设一对兔子的成熟期是一个月，即一个月可长成成兔，那么，如果每对成兔每个月都生一对小兔，
 *  一对新生的小兔从第二个月起就开始生兔子，试问从一对兔子开始繁殖，以后每个月会有多少对兔子？
*/

int main(int argc, char **argv){
    int mouths;
    if(argc==2) mouths = atoi(argv[1]);
    else {
        printf("please input mouth>>");
        scanf("%d",&mouths);
    } 
    //begin 
    int numberRabbit = 1;
    int babyRabbit = 0;
    int growingRabbit = 1;
    int adultRabbit = 0;
    int mouth = 2;
    if(mouths == 2 || mouths == 1) printf("2");
    while(mouth <= mouths){            //2 3 
        adultRabbit += growingRabbit;  //2 
        growingRabbit = babyRabbit;    //0 
        babyRabbit = adultRabbit;      //2 
        mouth++;
    }
    printf("%d",babyRabbit);
    return 0;
}
