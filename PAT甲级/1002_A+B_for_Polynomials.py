import random


def AB_for_Polynomials(line1, line2):

    K1 = line1[0]
    K2 = line2[0]
    D = dict()

    for i in range(1, 2 * K1, 2):
        D[line1[i]] = D.get(line1[i], 0.0) + line1[i+1]
    for i in range(1, 2 * K2, 2):
        D[line2[i]] = D.get(line2[i], 0.0) + line2[i+1]
    print(D)
    cnt = 0
    for i in range(1000):
        if(D.get(i)): 
            cnt += 1

    print(cnt, end="")
    for i in range(1000, -1, -1):
        if(D.get(i)):
            print(" ", end="")
            print( i, D.get(i), end="")

def random_line():
    line = []
    K = random.randint(1,5)
    line.append(K)
    for i in range(K):
        Ni = random.randint(1, 10)
        line.append(Ni)
        a_Ni = int(random.random() * 100) / 10
        line.append(a_Ni)
    return line

def test():
    line1 = random_line()
    print(line1)
    line2 = random_line()
    print(line2)
    AB_for_Polynomials(line1, line2)

if __name__=='__main__':
    # test()
    line1 = [1, 0, 0]
    line2 = [1, 0, 0]
    AB_for_Polynomials(line1, line2)
    # line1 = input().split(" ")
    # # print(line1)
    # line2 = input().split(" ")
