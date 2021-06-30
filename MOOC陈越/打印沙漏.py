def get_t(n):
    if n == 0: return (0,0)
    t = 1
    Sum = 1
    while(Sum <= n):
        t += 2
        Sum += 2 * t 
    return (t - 2, Sum - 2 * t)

def print_t(t, c):
    if t == 0: return
    k = 0  #空格数
    i = t 
    while(i >= 1): 
        print("".join([" " for _ in range(k)])+ \
        "".join([c for _ in range(i)]) )
        i -= 2
        k += 1
    i = 3 if t > 1 else 10000 #上一次的字符数是1
    k -= 2   #需要回退两格
    while(i <= t):
        print("".join([" " for _ in range(k)])+ \
        "".join([c for _ in range(i)]) )
        i += 2
        k -= 1
# n,c = input().split(" ")
# n = int(n)
c = "*"
for n in range(1000):
    print("n = %d"%n)
    t, Sum = get_t(n)
    print_t(t,c)
    if (n - Sum != 0): print(n - Sum)
    input()