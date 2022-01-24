import re
N = int(input())
s = ''
for i in range(1, N+1):
    s += str(i)
print(len(re.findall('1', s)))


