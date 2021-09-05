M, N, S = [int(_) for _ in input().split()] 
A = []
m = M
while m:
    m-=1
    A.append(input())

m = 0
n = 0
res = []
while m < M:
    if m == S - 1 + n * N:
        if A[m] in res:
            A.pop(m)
            M -= 1
            continue
        res.append(A[m])
        n += 1
    m += 1

if res:
    print("\n".join(res))
else:
    print("Keep going...")
    


