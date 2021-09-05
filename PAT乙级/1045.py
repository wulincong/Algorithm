N = int(input())
l = input().split(" ")
l = [int(_) for _ in l]
res = []
for i in range(N):
    # print(max(l[:i]) if l[:i] else 0)
    # print(min(l[i+1:]) if l[i+1:] else 10000000)
    if (l[i] >= (max(l[:i]) if l[:i] else 0)) and \
        (l[i] <= (min(l[i+1:]) if l[i+1:] else 10000000)):
        res.append(l[i])
print(len(res))
res.sort()
res = [str(_) for _ in res]
print(" ".join(res))

