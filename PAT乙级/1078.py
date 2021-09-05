ty = input()
S = input()
if ty == 'C':
    cnt = 1
    curr = S[0]
    for i in S[1:]:
        if i == curr:
            cnt += 1
        else:
            print("{}{}".format(str(cnt) if cnt > 1 else "", curr), end = "")
            cnt = 1
            curr = i
    print("{}{}".format(str(cnt) if cnt > 1 else "", curr), end = "")

elif ty == 'D':
    i = 0
    d = []
    while i < len(S):
        if S[i].isdigit():
            d.append(S[i])
        else:
            if(d):
                cnt = int("".join(d))
                while cnt:
                    print(S[i], end="")
                    cnt -= 1
                d = []
            else: print(S[i], end="")
        i += 1