first, N, K = input().split(" ")
N = int(N)
K = int(K)
dic = dict()
for i in range(N):
    Addr, Data, Next = input().split(" ")
    dic[Addr] = [Addr, Data, Next]
li = []
curr = first
while dic[curr][2] != '-1':
    li.append(dic[curr])
    curr = dic[curr][2]
li.append(dic[curr])
i = 0
res = []
while (i + 1) * K < N:
    tmp = li[i * K : (i + 1) * K]
    tmp.reverse()
    res += tmp
    i+=1
res += li[i * K:]
for i in range(N - 1):
    print("{} {} {}".format(res[i][0], res[i][1], res[i + 1][0]))
print("{} {} -1".format(res[N-1][0], res[N-1][1]))