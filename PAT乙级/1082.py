from math import sqrt

def distance(x, y):
    return sqrt( x**2 + y**2 )

if __name__ == '__main__':
    N = int(input())
    li = []
    while N:
        N -= 1
        Id, x, y = input().split(" ")
        li.append((Id, distance(int(x), int(y))))
    li = sorted(li, key=lambda x: x[1])
    print(li[0][0]+" "+li[-1][0])