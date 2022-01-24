N, b = (int(_) for _ in input().split(" "))

def baseToString(x, b):
    s = ""
    while x > 0:
        s = str(x % b) + s
        x = x // b
    return s

def isPalind(s):
    for i in range(0, len(s) // 2):
        if(s[i] != s[len(s) - i - 1]): return "No"
    return "Yes"

s = baseToString(N, b)
print(isPalind(s))
print(" ".join(list(s)))



