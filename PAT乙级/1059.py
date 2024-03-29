'''
1059 C语言竞赛 (20 分)
C语言竞赛是浙江大学计算机学院主持的一个欢乐的竞赛。既然竞赛主旨是为了好玩，颁奖规则也就制定得很滑稽：

 0、冠军将赢得一份“神秘大奖”（比如很巨大的一本学生研究论文集……）。
 1、排名为素数的学生将赢得最好的奖品 —— 小黄人玩偶！
 2、其他人将得到巧克力。
 给定比赛的最终排名以及一系列参赛者的 ID，你要给出这些参赛者应该获得的奖品。

输入格式：
 输入第一行给出一个正整数 N（≤10^4），是参赛者人数。随后 N 行给出最终排名，每行按排名顺序给出一位参
 赛者的 ID（4 位数字组成）。接下来给出一个正整数 K 以及 K 个需要查询的 ID。

输出格式：
 对每个要查询的 ID，在一行中输出 ID: 奖品，其中奖品或者是 Mystery Award（神秘大奖）、或者是
 Minion（小黄人）、或者是 Chocolate（巧克力）。如果所查 ID 根本不在排名里，打印 Are you 
 kidding?（耍我呢？）。如果该 ID 已经查过了（即奖品已经领过了），打印 ID: Checked（不能多吃
 多占）。
'''
def is_prime(n):
    if n == 2: return True
    i = 2
    while i * i <= n:
        if n % i == 0: return False
        i += 1
    return False

N = int(input())
n = 0
dic = {}
while n < N:
    id = input()
    dic[id] = [n, 0]
    n += 1
K = int(input())
while K:
    K-=1
    id = input()
    res = dic.get(id, [-1, -1])
    if res[1] == 1:
        print("{}: Checked".format(id))
    elif res[0] == 0 and res[1] == 0:
        print("{}: Mystery Award".format(id))
        res[1] = 1
    elif is_prime(res[0]) and res[1] == 0:
        print("{}: Minion".format(id))
        res[1] = 1
    elif res[0] == -1:
        print("{}: Are you kidding?".format(id))
    elif res[1] == 0:
        print("{}: Chocolate".format(id))
        res[1] = 1
