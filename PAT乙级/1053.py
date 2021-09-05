N, e, D = input().split(" ")
N = int(N)
e = float(e)
D = int(D)
n = N
mayK = 0
isK = 0
while n:
    n -= 1
    K, *Ei = list(input().split(" "))
    K = int(K)
    flag = 0
    cnt = 0
    for i in Ei:
        if float(i) < e:
            cnt += 1
    if cnt > K // 2:
        flag = 1
        mayK += 1
    if flag == 1 and K > D:
        isK += 1
        mayK -= 1

print("{:.1%} {:.1%}".format(mayK/N, isK/N))
