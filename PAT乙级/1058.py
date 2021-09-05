'''
1058 选择题 (20 分)
批改多选题是比较麻烦的事情，本题就请你写个程序帮助老师批改多选题，并且指出哪道题错的人
最多。

输入格式：
 输入在第一行给出两个正整数 N（≤ 1000）和 M（≤ 100），分别是学生人数和多选题的个数。随
 后 M 行，每行顺次给出一道题的满分值（不超过 5 的正整数）、选项个数（不少于 2 且不超过
 5 的正整数）、正确选项个数（不超过选项个数的正整数）、所有正确选项。注意每题的选项从小
 写英文字母 a 开始顺次排列。各项间以 1 个空格分隔。最后 N 行，每行给出一个学生的答题情
 况，其每题答案格式为 (选中的选项个数 选项1 ……)，按题目顺序给出。注意：题目保证学生的答
 题情况是合法的，即不存在选中的选项数超过实际选项数的情况。

输出格式：
 按照输入的顺序给出每个学生的得分，每个分数占一行。注意判题时只有选择全部正确才能得到该题
 的分数。最后一行输出错得最多的题目的错误次数和编号（题目按照输入的顺序从 1 开始编号）。
 如果有并列，则按编号递增顺序输出。数字间用空格分隔，行首尾不得有多余空格。如果所有题目都
 没有人错，则在最后一行输出 Too simple。
'''
import re
total = slice(0)
opt_nums = slice(1)
right_opts = slice(3, None)

N, M = input().split()
N = int(N)
M = int(M)

questions = {}
students = {}
m = 1
while m <= M:
    total, opt_nums, _, *right_opts = input().split()
    questions[m] = [int(total), opt_nums, right_opts, 0]
    m += 1
n = 1
while n <= N:
    wrong_times = slice(3)
    s = input()
    res = re.findall("\((.*?)\)", s) 
    for i, ans in enumerate(res):
        _, *student_ans = ans.split()
        if questions[i+1][2] == student_ans:
            students[n] = students.get(n, 0) + questions[i+1][0]
        else:
            questions[i+1][3] += 1
    n += 1
Max_wrong = max(questions.items(), key = lambda x: x[1][3])[1][3]
print("\n".join([str(_) for _ in students.values()]))
print(Max_wrong, end = "")
for i in questions.items():
    if i[1][3] == Max_wrong: print(" %d"%i[0], end = "")





