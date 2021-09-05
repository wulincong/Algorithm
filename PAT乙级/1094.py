
def isPrime(n:int)->bool:
    if n == 2: return True 
    i = 2 
    while i*i < n:
        if n % i == 0:
            return False
        i += 1
    return True


L, K = input().split(" ")
L = int(L)
K = int(K)
s = input()
i = 0
while i+K <= L:
    s_ = s[i:i+K]
    n = int(s_)
    if(isPrime(n)):
        print(s_)
        break
    i += 1
else:
    print(404)

