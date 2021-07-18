L = list(input())

M = {}

for i in L:
    if(i in M.keys()): M[i] += 1
    else: M[i] = 1

for i in range(10):
    if str(i) in M.keys(): 
        print("%s:%d" % (str(i), M[str(i)]))
