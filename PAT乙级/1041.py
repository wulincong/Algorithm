N = int(input())

n = N
dic = {}

while n:
    s_id, sit1, sit2 = input().split(" ")
    dic[sit1] = [s_id, sit2]
    n -= 1

input()
l = input().split(" ")
for i in l:
    print(" ".join(dic[i]))

