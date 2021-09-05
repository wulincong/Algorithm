level = slice(0)
class_id = slice(1,4)
year = slice(4,6)
month = slice(6, 8)
day = slice(8, 10)
date = slice(4, 10)
student_id = slice(10, 12)

N, M = input().split(" ")
N = int(N)
M = int(M)
dic = {}
n = N
while n:
    n -= 1
    admission, score = input().split(" ")
    score = int(score)
    dic[admission] = score

def mission_1(lel):
    '''按分数非升序输出某个指定级别的考生的成绩'''
    res = [(stu_adm, score) for stu_adm, score in dic.items() if stu_adm.startswith(lel)]
    res = sorted(res, key=lambda x:(x[1], 
    -ord(x[0][0]),
    -ord(x[0][1]),
    -ord(x[0][2]),
    -ord(x[0][3]),
    -ord(x[0][4]),
    -ord(x[0][5]),
    -ord(x[0][6]),
    -ord(x[0][7]),
    -ord(x[0][8]),
    -ord(x[0][9]),
    -ord(x[0][10]),
    -ord(x[0][11]),
    -ord(x[0][12]),
    ), reverse=True)
    if res:
        for i in res:
            print("{} {}".format(i[0], i[1]))
    else:
        print("NA")
def mission_2(cl_id):
    '''将某指定考场的考生人数和总分统计输出，对应的 指令 则给出指定考场的编号'''
    res = [score for stu_adm, score in dic.items() if stu_adm[class_id] == cl_id]
    if res:
        print("{} {}".format(len(res), sum(res)))
    else:
        print("NA")

def mission_3(d):
    '''将某指定日期的考生人数分考场统计输出，对应的 指令 则给出指定日期，格式与准考证上日期相同。
        输出按人数非递增顺序，格式为 考场编号 总人数。若人数并列则按考场编号递增顺序输出。
    '''
    res = {}
    for i in dic.keys():
        if(i[date] == d):
            res[i[class_id]] = res.get(i[class_id], 0) + 1
    res = res.items()
    res = sorted(res, key=lambda x:(-x[1], int(x[0])))

    if res:
        for i in res:
            print("{} {}".format(i[0], i[1]))
    else:
        print("NA")

if __name__ == '__main__':
    m = 1
    while m <= M:
        command, args = input().split(" ")
        print("Case {}: {} {}".format(m, command, args))
        eval("mission_{}(args)".format(command))
        m += 1

        
