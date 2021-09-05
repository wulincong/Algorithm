N, M = input().split(" ")
N = int(N)  #月饼的种类数
M = int(M)  #参与统计的城市数量

n = M  
cnt = {}

while n:
    n-=1
    l = [int(_) for _ in input().split(" ")]
    for i, j in enumerate(l):
        cnt[i+1] = cnt.get(i+1, 0) + j

Max = max(list(cnt.items()), key = lambda x:x[1])[1]
print(Max)

res = []
for i in cnt.keys():
    if cnt[i] == Max:
        res.append(str(i))
print(" ".join(res))

