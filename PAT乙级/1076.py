N = int(input())

n = N
keyDict = {
    'A':'1',
    'B':'2',
    'C':'3',
    'D':'4',
}
password = []
while n:
    answers = input().split(" ")
    for i in answers:
        if 'T' in i:
            ans, t = i.split("-")
            password.append(keyDict[ans])
    n -= 1

print("".join(password))