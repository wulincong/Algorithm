def isHuiwen(n):
    if(n == 0): return True
    s = str(n)
    k = len(s) - 1
    for i in range(k):
        if s[i] != s[k - i]:
            return False

    return True

def reverse_digit(n):
    l = list(str(n))
    l.reverse()
    return "".join(l)

if __name__ == '__main__':
    n = int(input())
    cnt = 10
    while not isHuiwen(n) and cnt:
        B_s = reverse_digit(n)
        B = int(B_s)
        C = n + B
        print("%d + %s = %d"%(n, B_s, C))
        n = C
        cnt -= 1
    
    if(cnt != 0):
        print("%d is a palindromic number."%n)
    else:
        print("Not found in 10 iterations.")




