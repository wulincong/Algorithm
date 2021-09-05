N, M = input().split(" ")
N = int(N)
M = int(M)
n = N
notR = []
while n:
    n -= 1
    a, b = input().split(" ")
    notR.append((a, b))
#print(notR)
m = M
while m:
    flag = 1
    m -= 1
    n, *l = input().split(" ")
    #print(l)
    for a, b in notR:
        if a in l and b in l:
            flag = 0
    print("Yes" if flag else "No")


