#include <stdio.h>

int main(int argc, char *argv[]){
    FILE *in = fopen(argv[1], "r");
    FILE *out = fopen(argv[2], "w");
    int a, b, c, count = 0;
    char line[100];
    char *s;
    while (fgets(line, 100, in) != NULL){
        sscanf(line, "%d %d %d", &a, &b, &c);
        printf("%d %d %d\n",a,b,c);
        count++;
        int flag = 0;
        for(size_t i = 11; i < 101; i++){
            flag = i%3 == a && i%5 == b && i%7 == c;
            if(flag){
                printf(" %d \n",i);
                fprintf(out,"Case %d:%d\n",count,i);
                break;
            }
        }
        if(!flag) {
            fprintf(out,"Case %d:No answer\n",count);
            printf("No answer\n");
        }
    }
    fclose(in);
    fclose(out);
}
