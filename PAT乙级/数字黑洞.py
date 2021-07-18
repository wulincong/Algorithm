i = input()
i += '0'*(4 - len(i))
if(len(set(list(i))) == 1):
    print(i + " - " + i + " = 0000")
    exit()
while(i != 6174):
    L = list(str(i))
    
    L.sort( reverse = True)
    a = int("".join(L))
    L1 = L[::-1]
    b = int("".join(L1))
    i = a - b
    print("".join(L) +" - " + "".join(L1) + " =", i)

