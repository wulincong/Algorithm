import math
def isPrime(n):
    if n == 1:
        raise Exception("1 is invalid!\n")
    elif n == 3: return True
    elif n == 2: return False
    Max = int(math.sqrt(n)) + 1
    for i in range(2, Max): 
        if n % i == 0: return False
    return True
def test_isPrime():
    while(1):
        N = int(input())
        print(isPrime(N))

if __name__=='__main__':
    # test_isPrime()
    N = int(input())
    j = 5
    cnt = 0
    if N < 5: 
        print("0")
    else:
        while(j <= N): 
            if isPrime(j) and isPrime(j-2):
                cnt += 1
            j += 1
        print(cnt)

