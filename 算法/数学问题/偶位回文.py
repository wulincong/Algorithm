import math

def isSushu(i):
    for k in range(2,int(math.sqrt(i))):
        if(i % k == 0):
            return 0
    return 1

def isHuiwen(number):
    array=list(number.__str__())
    if(array[0] == array[3] and array[1] == array[2]):return  1
    else: return 0

def findFactors(number):
    array=list()
    for k in range(2,int(math.sqrt(number))):
        if(number % k == 0):
            array.append(k)
    return array

def main():
    for i in range(1000,9999):
        if(i % 2 != 0):    #去除偶数
            if(isHuiwen(i)):  #是回文
                print(i , end=":")
                print(findFactors(i))

if __name__ == '__main__':
    main()

