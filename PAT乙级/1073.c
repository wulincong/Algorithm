#include <stdio.h>
/*
输入在第一行给出两个正整数 N（≤1000）和 M（≤100），分别是学生人数和多选题的个数。
随后 M 行，每行顺次给出一道题的满分值（不超过 5 的正整数）、选项个数（不少于 2 且
不超过 5 的正整数）、正确选项个数（不超过选项个数的正整数）、所有正确选项。注意每
题的选项从小写英文字母 a 开始顺次排列。各项间以 1 个空格分隔。最后 N 行，每行给出
一个学生的答题情况，其每题答案格式为 (选中的选项个数 选项1 ……)，按题目顺序给出。注
意：题目保证学生的答题情况是合法的，即不存在选中的选项数超过实际选项数的情况。
N M 
total_score opts_number right_num 
*/
int main(int argc, char **argv){
    int N, M;
    int total_score, opts_number, right_num;
    scanf("%d %d", &N, &M);
    int Questions[M][256], Answers[M][256];
    float Scores[N];

    for(int i = 0; i < N; i++)Scores[i] = 0.0;
    for(int i = 0; i < M; i++) for(int j = 0; j < 256; j++){Questions[i][j] = 0;Answers[i][j] = 0;}

    for(int i = 0; i < M; i++){
        char t_c;
        scanf("%d %d %d", &Questions[i][0], &Questions[i][1], &right_num);
        for(int j = 0; j < right_num; j++){
            scanf(" %c", &t_c);
            Questions[i][t_c] = 1;
        }
        Questions[i][2] = right_num;
        Questions[i][3] = 0;
    }
    getchar();
    for(int i = 0; i < N; i++){ //第i个学生
        float score = 0.0;
        char t_c= '\0';
        int q = -1, flag = 0;
        while(t_c != '\n'){
            t_c = getchar();
            if(t_c == '(') q++;
            if(t_c < 'g' && t_c >= 'a')
                Answers[q][t_c] = 1;
        }
        for(int j = 0; j < M; j++){
            for(char c = 'a'; c < 'a'+ Questions[j][1]; c++){
                if(Questions[j][c] && Answers[j][c] == 0 && flag == 0)flag = 1;//有少选
                if(Questions[j][c] == 0 && Answers[j][c]){
                    Questions[j][c] ++;
                    flag = 2;//有错选
                }
            }
            if(flag == 0)score += (float)Questions[j][0];
            else if(flag == 1) score += (float)Questions[j][0] * 0.5;
        }
        Scores[i] = score;   

    }

    for(int i = 0; i < N; i++){
        printf("%.1f\n", Scores[i]);
    }
}
