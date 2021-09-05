def is_empty(dic):
    for i in dic.keys():
        if dic[i]:return False
    return True

l = list(input())

pat_test = list("PATest")

dic = {'P':0, 'A':0, 'T':0, 'e':0, 's':0, 't':0}

for i in l:
    if i in pat_test:
        dic[i] += 1

while not is_empty(dic):
    for i in pat_test:
        if dic[i] > 0:
            dic[i] -= 1
            print(i, end="")
