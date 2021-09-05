def sTolist(S):
    l = []
    flag = 0
    chs = ''
    for i in S:
        if i == '[':flag = 1
        elif i == ']':
            flag = 0
            l.append(chs)
            chs = ''
        else:
            if flag:
                chs += i
    return l

shou = sTolist(input())
yan = sTolist(input())
kou = sTolist(input())

n = int(input())
while n:
    n-=1
    a, b, c, d, e = [int(_) for _ in input().split(" ")]

    if a > len(shou) or b > len(yan) or c > len(kou) or d > len(yan) or e > len(shou):
        print("Are you kidding me? @\\/@")
    else:
        print("{}({}{}{}){}".format(shou[a-1], yan[b-1], kou[c-1], yan[d-1], shou[e-1]))