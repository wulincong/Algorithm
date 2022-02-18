N = int(input())
li = [int(_) for _ in input().split(" ")]
for i in range(1, N):
    if i not in li:
        print(i)
        break