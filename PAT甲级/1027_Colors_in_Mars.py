li = [int(_) for _ in input().split(" ")]
res = ''
for i in li:
    s = ''
    while i > 0:
        n = i % 13
        if(n == 10): s = 'A' + s
        elif (n == 11): s = 'B' + s
        elif (n == 12): s = 'C' + s
        else: s = str(n) + s
        i = i // 13
    res += s

print("#%s"%res)

