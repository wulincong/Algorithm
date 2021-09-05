e_m = "tret, jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec".split(", ")
e_m_in = "0, tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou".split(", ")

m_e = {}
m_e_in = {}
for i in range(13):
    m_e[e_m[i]] = i
    m_e_in[e_m_in[i]] = i

def earthToMars(n):
    l = [e_m[n % 13],]
    n = n // 13
    while n > 0:
        l.append(e_m_in[n % 13])
        n = n // 13
    return " ".join(l[::-1])

def marsToEarth(s):
    l = s.split(" ")
    if len(l) == 1:
        num = m_e.get(s, 0) + m_e_in.get(s, 0) * 13
        return num
    n = [m_e[l[-1]],]
    for i in l[::-1][1:]:
        n.append(m_e_in[i])
    cnt = 0
    num = 0
    for i in n:
        num += 13 ** cnt * i
        cnt += 1
    return num

N = int(input())
while N:
    N -= 1
    n = input()
    if n.isdigit():
        n = int(n)
        print(earthToMars(n))
    else:
        print(marsToEarth(n))
