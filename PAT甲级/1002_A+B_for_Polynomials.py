line1 = input().split(" ")
# print(line1)
line2 = input().split(" ")

K1 = int(line1[0])
K2 = int(line2[0])
D = dict()


for i in range(1, 2 * K1, 2):
    D[line1[i]] = D.get(line1[i], 0.0) + float(line1[i+1])
    D[line2[i]] = D.get(line2[i], 0.0) + float(line2[i+1])

cnt = 0
for i in range(1000):
    if(D.get(str(i))): 
        cnt += 1

print(cnt, end="")
for i in range(1000, -1, -1):
    if(D.get(str(i))):
        print(" ", end="")
        print( i, D.get(str(i)), end="")