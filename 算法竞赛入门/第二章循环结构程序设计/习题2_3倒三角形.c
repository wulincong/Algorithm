#include <stdio.h>

int main(int argc, char *argv[]){
    int high = -1,space = 0;
    if(argc > 1) high = atoi(argv[1]);
    else scanf("%d",&high);
    while(high--){
        int num_space = space;
        while(num_space--) printf(" ");
        space++;
        for(int i = 2 * high + 1; i > 0; i--)
            printf("#");
        printf("\n");
    }
}
