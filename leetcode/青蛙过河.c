#include <stdio.h>
#include <stdlib.h>
#define bool int
typedef struct jmpNode{
    int currentPosition;
    size_t last_jmp;
    struct jmpNode * nextLeftStone;
    struct jmpNode * nextMidStone;
    struct jmpNode * nextRightStone;

}*jmpStonep;

int flag = 0;

int iin(int * stones, int currentPosition, int nextJmp){
    int nextStone = stones[currentPosition] + nextJmp;
    int position = 0;
    for(size_t i = currentPosition; stones[i] <= nextStone;i++){
        if(stones[i] == nextStone){
            position = i;
            break;
        }
    }
    return position;
} 


int findNextJmp(jmpStonep p,int *stones){
    if(p->last_jmp == 0){
        int nextRightStonePos;
        if(nextRightStonePos = iin(stones,p->currentPosition,1) ){
            jmpStonep nextRightStonep = (jmpStonep)malloc(sizeof(jmpStonep));
            nextRightStonep->last_jmp = 1;
            nextRightStonep->currentPosition = nextRightStonePos;
            p->nextRightStone = nextRightStonep;
            return 1;
        }
    }
    else if(p->last_jmp == 1){
        int nextMidStonePos,nextRightStonePos;
        if(nextMidStonePos = iin(stones,p->currentPosition,1) ){
        jmpStonep nextMidStonep = (jmpStonep)malloc(sizeof(jmpStonep));
        nextMidStonep->currentPosition = nextMidStonePos;
        nextMidStonep->last_jmp = 1;
        p->nextRightStone = nextMidStonep;
        }
        if(nextRightStonePos = iin(stones,p->currentPosition,2) ){
        jmpStonep nextRightStonep = (jmpStonep)malloc(sizeof(jmpStonep));
        nextRightStonep->currentPosition = nextRightStonePos;
        nextRightStonep->last_jmp = 2;
        p->nextRightStone = nextRightStonep;
        }
        return 1;
    }
    else{
        int nextLeftStonePos,nextMidStonePos,nextRightStonePos;

        if(nextLeftStonePos = iin(stones,p->currentPosition,p->last_jmp-1)){
            jmpStonep nextLeftStonep = (jmpStonep)malloc(sizeof(jmpStonep));
            nextLeftStonep->currentPosition = nextMidStonePos;
            nextLeftStonep->last_jmp = nextLeftStonePos ;
            p->nextLeftStone = nextLeftStonep;
        }
        if(nextMidStonePos = iin(stones,p->currentPosition,p->last_jmp) ){
        jmpStonep nextMidStonep = (jmpStonep)malloc(sizeof(jmpStonep));
        nextMidStonep->currentPosition = nextMidStonePos;
        nextMidStonep->last_jmp = p->last_jmp;
        p->nextMidStone = nextMidStonep;
        }
        if(nextRightStonePos = iin(stones,p->currentPosition,p->last_jmp+1)){
            jmpStonep nextRightStonep = (jmpStonep)malloc(sizeof(jmpStonep));
            nextRightStonep->currentPosition = nextRightStonePos;
            nextRightStonep->last_jmp = p->last_jmp +1;
            p->nextRightStone = nextRightStonep;
        }
        return 1;
    }
    return 0;
}



int nextJmp(int * stones, jmpStonep p,int stonesSize){
    findNextJmp(p,stones);

    if(p->nextLeftStone->currentPosition == stonesSize |
       p->nextMidStone->currentPosition == stonesSize |
       p->nextRightStone->currentPosition == stonesSize) 
       {
           flag = 1;
           return 1;
       }
    if(p->nextLeftStone != NULL) 
        nextJmp(stones,p->nextLeftStone,stonesSize);
    if(p->nextMidStone != NULL ) nextJmp(stones,p->nextMidStone,stonesSize);
    if(p->nextLeftStone != NULL) nextJmp(stones,p->nextLeftStone,stonesSize);
}

bool canCross(int* stones, int stonesSize){
    size_t last_jmp = 0;
    jmpStonep firstStone;
    nextJmp(stones,firstStone,stonesSize);
    if(flag == 1) return 1;
    return 0;
}

int main(int argc, char ** argv){
    int stones[8] = {0,1,3,5,6,8,12,17};
    if(canCross(stones,8))
        printf("true\n");
    else printf("false\n");
}