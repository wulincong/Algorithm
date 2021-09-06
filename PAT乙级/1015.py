'''
1015 德才论 (25 分)
 宋代史学家司马光在《资治通鉴》中有一段著名的“德才论”：“是故才德全尽谓之圣人，才德兼亡谓之愚
 人，德胜才谓之君子，才胜德谓之小人。凡取人之术，苟不得圣人，君子而与之，与其得小人，不若得愚
 人。”
 现给出一批考生的德才分数，请根据司马光的理论给出录取排名。

输入格式：
 输入第一行给出 3 个正整数，分别为：N（≤10^5），即考生总数；L（≥60），为录取最低分数线，
 即德分和才分均不低于 L 的考生才有资格被考虑录取；H（<100），为优先录取线——德分和才分均不
 低于此线的被定义为“才德全尽”，此类考生按德才总分从高到低排序；才分不到但德分到线的一类考生
 属于“德胜才”，也按总分排序，但排在第一类考生之后；德才分均低于 H，但是德分不低于才分的考生
 属于“才德兼亡”但尚有“德胜才”者，按总分排序，但排在第二类考生之后；其他达到最低线 L 的考生
 也按总分排序，但排在第三类考生之后。

 随后 N 行，每行给出一位考生的信息，包括：准考证号 德分 才分，其中准考证号为 8 位整数，德才
 分为区间 [0, 100] 内的整数。数字间以空格分隔。

输出格式：
 输出第一行首先给出达到最低分数线的考生人数 M，随后 M 行，每行按照输入格式输出一位考生的信
 息，考生按输入中说明的规则从高到低排序。当某类考生中有多人总分相同时，按其德分降序排列；若
 德分也并列，则按准考证号的升序输出。
'''

N, L, H = [int(_) for _ in input().split(" ")]
dic = {}
n = N
while n:
    n -= 1
    id, de, cai = input().split(" ")
    de = int(de)
    cai = int(cai)
    if de >= H and cai >= H:
        l = 1
    elif de >= H and L <= cai < H:
        l = 2
    elif L <= de < H and de > cai and L <= cai < H:
        l = 3
    elif de >= L and cai >= L:
        l = 4
    else:
        l = 0
    dic[id] = [de, cai, l]

L1 = [_ for _ in dic.items() if _[1][2] == 1]
L2 = [_ for _ in dic.items() if _[1][2] == 2]
L3 = [_ for _ in dic.items() if _[1][2] == 3]
L4 = [_ for _ in dic.items() if _[1][2] == 4]
L1 = sorted(L1, key=lambda x: (x[1][0] + x[1][1], x[1][0], -int(x[0])), reverse=True)
L2 = sorted(L2, key=lambda x: (x[1][0] + x[1][1], x[1][0], -int(x[0])), reverse=True)
L3 = sorted(L3, key=lambda x: (x[1][0] + x[1][1], x[1][0], -int(x[0])), reverse=True)
L4 = sorted(L4, key=lambda x: (x[1][0] + x[1][1], x[1][0], -int(x[0])), reverse=True)
print(len(L1) + len(L2) + len(L3) + len(L4))
for i in L1:
    print("{} {} {}".format(i[0], i[1][0], i[1][1]))
for i in L2:
    print("{} {} {}".format(i[0], i[1][0], i[1][1]))
for i in L3:
    print("{} {} {}".format(i[0], i[1][0], i[1][1]))
for i in L4:
    print("{} {} {}".format(i[0], i[1][0], i[1][1]))


    
    