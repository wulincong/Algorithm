#include <stdio.h>
int main(int argc, char *argv[]){
    FILE  *File = fopen(argv[1], "r");
    int T, i, School, Score, MaxSchoolID = 1;
    fscanf(File, "%d", &T);
    int Scores[T] = {0};
    i = T;
    while(i--){
        fscanf(File, "%d%d", &School, &Score);
        Scores[School] += Score;
    }
    for(i = 1; i <= T; i++){
        if(Scores[MaxSchoolID] < Scores[i])MaxSchoolID = i;
    }
    printf("%d %d\n", MaxSchoolID,Scores[MaxSchoolID]);
    return 0;
}