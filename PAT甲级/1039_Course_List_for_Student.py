def query(dic: dict, id):
    cnt = 0
    li = []
    for key in dic.keys():
        if id in dic[key]:
            cnt += 1
            li.append(key)
    print(cnt, end='')
    if(li):
        print(" ", end='')
        li = sorted(li)
        print(" ".join(li))

N, K =[int(i) for i in  input().split(" ")]

dic = dict()

for i in range(K):
    key = input().split(" ")[0]
    dic[key] = input().split(" ")

query_set = input().split(" ")
for i in query_set:
    print(i, end=' ')
    query(dic, i)    



