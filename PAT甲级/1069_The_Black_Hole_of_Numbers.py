s = input()
res = list(s)

while "".join(res) != "6174":
    a = int("".join(sorted(res, reverse=True)))
    b = int("".join(sorted(res)))
    if a == b:
        print("%04d - %04d = %04d"%(a, b, 0))
        break
    c = a - b
    print("%04d - %04d = %04d"%(a, b, c))
    res = list(str(c))



