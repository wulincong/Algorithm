N = int(input())
res = []
D = {
    '1' : '@',
    '0' : '%',
    'l' : 'L',
    'O' : 'o',
}
for i in range(N):
    flag = 0
    name, pwd = input().split(" ")
    pwd = list(pwd)
    for j in range(len(pwd)):
        c = pwd[j]
        if(D.get(c, '')):
            pwd[j] = D.get(c, c)
            flag = 1
    if(flag):
        res.append([name,"".join(pwd)])
print(len(res))
for i in res:
    print(" ".join(i))