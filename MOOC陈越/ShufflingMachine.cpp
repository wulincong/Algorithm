#include <cstdio>
using namespace std;

int main(int argc, char **argv){
    int cnt;
    scanf("%d",&cnt);
    int start[55], end[55], scan[55];
    //读入用于变换的数组
    for(int i = 1; i < 55; i++){
        scanf("%d",&scan[i]);
        end[i] = i;
    }
    for(int i = 0; i < cnt; i++){
        for(int j = 1; j < 55; j++) start[j] = end[j];  //下次排序之前start要变成end
        for(int k = 1; k < 55; k++) end[scan[k]] = start[k];  //洗牌操作
    }
    //打印
    char c[6] = {"SHCDJ"};
    for(int i = 1; i < 55; i++){
        end[i] = end[i] - 1;
        printf("%c%d", c[end[i] / 13], end[i] % 13 + 1);
        if(i != 54) printf(" ");
    }
    return 0;
}