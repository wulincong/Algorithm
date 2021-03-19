#include <stdio.h>
int main(int argc,char *argv[]){
    int testNumber, A, B, C;
    //FILE *inputFile = fopen(argv[1], "r");
    scanf( "%d",&testNumber);
    for(size_t i = 0;i < testNumber; i++){
        scanf( "%d%d%d",&A,&B,&C);
        if(A+B>C)printf("true\n",i);
        else printf("false\n",i);
    }
    //fclose(inputFile);
    return 0;
}
