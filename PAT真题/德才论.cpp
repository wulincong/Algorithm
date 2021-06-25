#include <stdio.h>
#include <algorithm>
typedef struct{
    int id;    
    int De;    
    int Cai;    
} Student; //德才兼备


int main(int argc, char *argv[]){
    int N,L,H;
    scanf("%d%d%d",&N,&L,&H);
    Student Students[N];
    for (size_t i = 0; i < N; i++)
    {
        scanf("%d %d %d",Students[i].id,Students[i].De,Students[i].Cai);
    }
    int bestStudent = 0;
    int level1 = 0,level2 = 0,level3 = 0;
    
    
}