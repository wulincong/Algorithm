#include <stdio.h>

int toPrint(int res){
    int flag = 1;
    if (res < 0) {
        flag = -1;
        res *= -1;
    }
    int Galleon, Sickle, Kunt;
    Kunt = res % 29;
    res /= 29;
    Sickle = res % 17;
    res /= 17;
    Galleon = res;
    if(flag == -1)
        printf("-%d.%d.%d\n", Galleon, Sickle, Kunt);
    else printf("%d.%d.%d\n", Galleon, Sickle, Kunt);
    return 0;
}

int main(int argc, char **argv){
    int PGalleon, AGalleon, PSickle, ASickle, PKunt, AKunt;
    scanf("%d.%d.%d %d.%d.%d", &PGalleon, &PSickle, &PKunt, &AGalleon, &ASickle, &AKunt);
    long long P = PGalleon * 17 * 29 + PSickle * 29 + PKunt;
    long long A = AGalleon * 17 * 29 + ASickle * 29 + AKunt;
    long long result = A - P;
    toPrint(result);
    return 0;
}