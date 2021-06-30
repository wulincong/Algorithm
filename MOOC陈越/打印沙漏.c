#include <stdio.h>

// int main(int argc, char *argv[]){
//     int n;
//     char a;
//     scanf("%d %c", &n, &a);
//     if (n == 0) return 0;
//     int sum = 1;
//     int i = 1;
//     while(sum <= n){
//         i += 2;
//         sum += i * 2;
//     }
//     sum -= 2 * i;
//     i -= 2;
//     int t = i;
//     int k = 0;
//     while(t > 1){
//         for(size_t j = 0; j < k; j++) printf(" ");
//         for(size_t j = 0; j < t; j++) printf("%c", a);
//         printf("\n");
//         t -= 2;
//         k++;
//     }
//     for(size_t j = 0; j < k; j++) printf(" ");
//     printf("%c\n", a);
//     t += 2;
//     k--;
//     while (t <= i){
//         for(size_t j = 0; j < k; j++) printf(" ");
//         for(size_t j = 0; j < t; j++) printf("%c", a);
//         printf("\n");
//         t += 2;
//         k--;
//     }
//     if(n - sum != 0) printf("%d\n",n - sum);

// }

int main(){ 
    int n,sum=1,m=0,temp=1; 
    char x; 
    scanf("%d",&n); 
    getchar(); 
    scanf("%c",&x); 
    if(n==1){ 
        printf("%c\n",x); 
        printf("0\n");
	}
    else{ 
        while(n>sum){ 
            m+=1; 
            temp=(temp+2); 
            sum+=temp*2; 
            } 
        temp-=2; 
        m-=1; 
        for(int i=0;i<m;i++){ 
            for(int j=0;j<i;j++){ 
                printf(" "); 
            } 
            for(int j=0;j<temp-i*2;j++){ 
                printf("%c",x); 
            } 
            printf("\n"); 
            } 
            for(int i=0;i<m;i++){ 
                printf(" ");
	        } 
            printf("%c\n",x); 
            for(int i=m-1;i>=0;i--){ 
                for(int j=0;j<i;j++){ 
                    printf(" "); 
                } 
                for(int j=0;j<temp-i*2;j++){ 
                    printf("%c",x); 
                } 
                printf("\n"); 
                } 
                printf("%d\n",n-sum+(temp+2)*2);
} return 0;
}
