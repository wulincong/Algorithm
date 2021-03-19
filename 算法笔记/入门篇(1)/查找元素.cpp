#include <stdio.h>
int main(int argc, char *argv[]){
    FILE *File = fopen(argv[1], "r");
    int n, i, Target;
    fscanf(File, "%d", &n);
    int Arr[n];
    for ( i = 0; i < n; i++) fscanf(File, "%d", &Arr[i]);
    //for (i = 0; i < n; i++) printf("%d ",Arr[i]);
    fscanf(File, "%d",&Target);
    for (i = n-1; i >= 0; i--) {
        if(Arr[i] == Target) break;
    }
    printf("%d",i);
    return 0;
}