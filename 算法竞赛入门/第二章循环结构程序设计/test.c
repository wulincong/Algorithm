#include <stdio.h>

int main(int argc, char *argv[]){
    FILE *File = fopen(argv[1], "w");
    int num; //
    scanf("%d",&num);
    fprintf(File,"the number is %d\n",num);
}