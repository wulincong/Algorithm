#include <stdio.h>
typedef int bool;
#define true 1 
#define false 0

int main(){
    int N, A1 = 0, A2 = 0, A3 = 0, A5 = 0, temp;
    float A4 = 0;
    int numberA4 = 0,numberA2 = 0;
    bool flag = true;
    scanf("%d",&N);
    for(size_t i = 0; i < N; i++){
        scanf("%d",&temp);
        if(!(temp % 5) && !(temp % 2))A1 += temp;
        //A2 = 将被5除后余1的数字按给出顺序进行交错求和，即计算n1-n2+n3-n4...；
        if((temp % 5 == 1)){
            numberA2 ++;
            if(flag) {
                A2 += temp;
                flag = false;
            }
            else {
                A2 -= temp;
                flag = true;
            }
            
        }
        //A3 = 被5除后余2的数字的个数；
        if(temp % 5 == 2) A3++;
        //A4 = 被5除后余3的数字的平均数，精确到小数点后1位；
        if(temp % 5 == 3){
            A4 += temp;
            numberA4 ++;
        }
        //A5 = 被5除后余4的数字中最大数字。
        if(temp % 5 == 4){
            if(temp > A5) A5 = temp;
        }
    }
    if(!A1 )printf("N ");else printf("%d ",A1);
    if(!numberA2)printf("N ");else printf("%d ",A2);
    if(!A3)printf("N ");else printf("%d ",A3);
    if(!A4)printf("N ");else printf("%.1f ",A4 / numberA4 );
    if(!A5)printf("N");else printf("%d",A5);
    return 0;
}