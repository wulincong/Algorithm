N = int(input())

dic = {}

while N:
    N -= 1
    stu_id, score, school_id = input().split(" ")
    score = int(score)
    school_id = school_id.lower()
    _ = dic.get(school_id, [0, 0]) 
    if stu_id[0] == 'B':_[0] += score / 1.5
    elif stu_id[0] == 'A':_[0] += score
    elif stu_id[0] == 'T':_[0] += score * 1.5
    _[1] += 1
    dic[school_id] = _

for i in dic.keys():
    dic[i][0] = int(dic[i][0])

sort_schools = sorted(list(dic), key=lambda x: (-dic[x][0], dic[x][1], x))

print(len(sort_schools))

rank = 0
pre = 0
for i in sort_schools:
    if not pre == dic[i][0]:
        rank += 1
    print("{} {} {} {}".format(rank, i, dic[i][0], dic[i][1]))
    pre = dic[i][0]
