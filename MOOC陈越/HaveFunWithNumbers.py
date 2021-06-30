N = int(input())

M = 2*N 
flag = 'Yes' if set(list(str(N))) == set(list(str(M))) else 'No'
print(flag)
print(M)