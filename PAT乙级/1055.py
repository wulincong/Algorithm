def ZD(l):
    lis = sorted(l, key= lambda x: (x[1], -ord(x[0][0]), -ord(x[0][1]) ), reverse=True)
    flag = 0
    res = [lis[0][0]]
    for i in lis[1:]:
        if(flag == 0):
            res.insert(0, i[0])
            flag = -1
        else:
            res.append(i[0])
            flag = 0
    return " ".join(res)

N, K = [int(_) for _ in input().split(" ")]
n = N
students = []
while n:
    n -= 1
    student = (name, height) = input().split(" ")
    student[1] = int(student[1])
    students.append(student)
students = sorted(students, key = lambda x: x[1])
pre_lin = N // K
lines = []
for i in range(pre_lin):
    if (i + 2) * K < len(students):
        begin = i * K
        end = (i+1)*K
        lines.append(students[begin : end])
    else:
        begin = i * K
        lines.append(students[begin :])
for i in lines[::-1]:
    print(ZD(i))




