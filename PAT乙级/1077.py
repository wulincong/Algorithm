N, M = input().split(" ")
N = int(N)  #分组数
M = int(M)  #满分
n = N

while n:
    score = [int(_) for _ in input().split(" ")] 
    G2 = score[0]
    others = score[1:]
    others = [x for x in others if x >= 0 and x <= M ]
    G1 = (sum(others) - max(others) - min(others)) / (len(others) - 2)
    G = round((G1 + G2 + 0.0001) / 2)
    print(G)
    n -= 1


