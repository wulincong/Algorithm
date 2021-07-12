#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define TRUE 1 
#define FALSE 0
#define EQUL -1
#define nul -1
typedef int BOOL;

struct TM {
    int year;
    int month;
    int day;
    int index;
};

struct TM today = {2014, 9, 6, nul};
struct TM firstDay = {2014 - 200, 9, 6, nul};

BOOL min(struct TM *a, struct TM *b){
    if(a->year < b->year) return FALSE;
    else if(a->year > b->year) return TRUE;
    else{
        if(a->month < b->month) return FALSE;
        else if(a->month > b->month) return TRUE;
        else{
            if(a->day < b->day) return FALSE;
            else return TRUE;
        }
    }
}

BOOL isLegal(struct TM *a){
    if(min(a, &firstDay) == FALSE || min( &today, a) == FALSE ) return FALSE;
    else return TRUE;
}

int main(int argc, char **argv){
    //John 2001/05/12
    int N, cnt = 0;
    struct TM tm, \
    maxt = today, \
    mint = firstDay;
    scanf("%d", &N);
    char names[N][6];
    for (size_t i = 0; i < N; i++)
    {
        scanf("%s", &names[i]);
        scanf("%d/%d/%d", &tm.year, &tm.month, &tm.day);
        tm.index = i;
        if(isLegal(&tm)) {
            // printf("OK\n");
            cnt += 1;
            if(min(&tm, &mint)) mint = tm;
            else if(min(&maxt, &tm)) printf("OK");
            printf("%d\n", maxt.index);
        }
    }
    printf("%d ", cnt);
    printf("%s %s\n", \
    maxt.index != -1 ? names[maxt.index] :names[mint.index] \
    , mint.index != -1 ? names[mint.index] :names[maxt.index]
    );

}
