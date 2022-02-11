def isPalind(n):
    li = list(str(n))
    for i in range(len(li)//2):
        if li[i] != li[len(li) - 1 - i]:
            return False
    return True

N, K = input().split(" ")
N = int(N) 
K = int(K)
cnt = 0
while(cnt < K):
    if isPalind(N):
        print("%d\n%d"%(N, cnt))
        break
    else:
        li = list(str(N))
        li.reverse()
        N += int("".join(li))
        cnt += 1
if cnt == K:
    print("{}\n{}".format(N, K))