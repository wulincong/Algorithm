N = int(input())
rand = [int(_) for _ in input().split(" ")]
dic = {}

for i in range(N):
    num = rand[i] - (i + 1)
    num = num if num >= 0 else -num
    dic[num] = dic.get(num, 0) + 1

sort_num = sorted(list(dic), reverse=True)

for i in sort_num:
    if dic[i] > 1:
        print("{} {}".format(i, dic[i]))




