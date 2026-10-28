r = [-1] * 100

def cut_rod_aux(p, n):
    """p 价格、 n钢条长度"""
    if r[n] >= 0:
        return r[n]
    if n == 0:
        q = 0
    else: 
        q = -1
        for i in range(1, n + 1):
            q = max(q, p[i] + cut_rod_aux(p, n-i))
    r[n] = q
    return q

prices = [0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30]

print(cut_rod_aux(prices, 4))
