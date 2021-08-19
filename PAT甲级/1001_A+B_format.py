
def ABFormat(A, B):
    C = A + B
    C_flag = ''
    if C < 0: 
        C_flag = '-'
        C = -C
    C_str = str(C)
    print(C_str)
    S_tmp = ""
    flag = -1

    for i in range(len(C_str), 0, -1): 
        flag += 1
        if(flag % 3 == 0 and flag != 0):
            S_tmp += ","
        S_tmp += C_str[i - 1]
    print("{flag}{num}".format(num = S_tmp[::-1], flag = C_flag))

def test():
    for A in range(-1000000, 1000000, 100000):
        for B in range(-1000000, 1000000, 100000):
            ABFormat(A, B)

if __name__ == '__main__':
    test()
    # A, B = input().split(" ")
    # A = int(A)
    # B = int(B)
    # ABFormat(A, B)