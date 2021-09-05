l = list(input())

dic = {}

for i in l:
    if i.isalpha():
        i = i.lower()
        dic[i] = dic.get(i, 0) + 1

c = list(dic.keys())[0]
m = dic[c]

for i in dic.keys():
    if dic[i] >= m and i < c:
        c = i 
        m = dic[i]
        

print(c + " " + str(m))
