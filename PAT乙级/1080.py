P, M, N = input().split(" ")
# P（做了在线编程作业的学生数）、
# M（参加了期中考试的学生数）、
# N（参加了期末考试的学生数）

class Student:

    def __init__(self, name, Gp = -1):
        self.name = name
        self.Gp = Gp
        self.Gmin_term = -1
        self.Gfinal = -1
        self.G = -1
    
    def getG(self):
        self.G = (self.Gmin_term * 0.4 + self.Gfinal * 0.6) \
            if self.Gmin_term > self.Gfinal else self.Gfinal
        return self.G

    def __str__(self):
        return "{} {} {} {} {}".format( self.name, 
                                        round(self.Gp ),
                                        round(self.Gmin_term),
                                        round(self.Gfinal),
                                        round(self.G) )

n = int(P)
List = {}

while n:
    name, Gp = input().split(" ")
    Gp = int(Gp)
    List[name] = Student(name, Gp)
    n -= 1

n = int(M)
while n:
    name, Gm = input().split(" ")
    Gm = int(Gm)
    if name in List.keys():
        List[name].Gmin_term = Gm
    n -= 1

n = int(N)
while n:
    name, Gf = input().split(" ")
    Gf = int(Gf)
    if name in List.keys():
        List[name].Gfinal = Gf
    n -= 1
res = []
for i in List.keys():
    student = List[i]
    student.getG()
    if(student.Gp >= 200 and student.G >= 60):
        res.append(student)

res = sorted(res, key=lambda x: (x.G, -ord(x.name[0])), reverse=True)
#res = sorted(res, key=lambda x: x.name)
for i in res:
    print(i)
