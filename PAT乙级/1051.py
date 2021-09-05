from math import sin, cos

def toNormal(R, Pi):
    j = 0+1j
    return R*(cos(Pi) + sin(Pi)*j)

if __name__ == '__main__':
    R1, P1, R2, P2 = input().split(" ")
    res = toNormal(float(R1), float(P1)) * toNormal(float(R2), float(P2))
    print("{:.2f}{}{:.2f}i".format(res.real,\
        '+' if res.imag > 0 else '',\
         res.imag))
