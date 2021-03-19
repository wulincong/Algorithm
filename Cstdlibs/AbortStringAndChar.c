#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]){
    size_t len = strlen(argv[1]);
    {
        double x = atof(argv[1]);  //the parameter must start with number, allowed end with characters except 'E' or 'e'
        printf("%lf\n", x);
    }
    {
        int x = atoi(argv[1]);  //the parameter must start with number,allowed end with characters;
        printf("%d\n", x);
    }
    {
        long x = atol(argv[1]); //the parameter must start with number,allowed end with characters;
        printf("%ld \n",x);
    }
    {
        printf("+-----+----------+\n");
        for (size_t i = 0; i < len; i++)
        {
            printf("|%-5d|",i);
            if(isdigit(argv[1][i])) printf("  d  ");
            if(isalpha(argv[1][i])) printf("  a  ");
            if(isgraph(argv[1][i])) printf("  g  ");else printf("  c  ");
            
            
            printf("|");
        printf("\n+-----+----------+\n");
        }
        
    }
    return 0;
}