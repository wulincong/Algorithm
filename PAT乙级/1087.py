N = int(input())
cnt = 0
s = set()

for i in range(1, N + 1):
    cnt = int(i / 2) + int(i / 3) + int(i / 5)
    s.add(cnt)
# print(s)
print(len(s))