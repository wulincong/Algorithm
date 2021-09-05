N = int(input())

l = [int(_) for _ in input().split()]

l = sorted(l)
res = 0
for i in l:
    res = (res + i) / 2

print(int(res))