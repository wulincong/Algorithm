jia = yi = bing = 99
M, X, Y = [int(_) for _ in input().split(" ")]
flag = 0
while jia >= 10 and not flag:
    jia -= 1
    yi = int(str(jia)[::-1])
    cha = jia - yi if jia > yi else yi - jia
    bing = cha / X
    if(bing * Y == yi): 
        flag = 1
        break
if not flag:print("No Solution")
else: print("{} {} {} {}".format(
    jia,
    "Cong" if M < jia else "Ping" if M == jia else "Gai",
    "Cong" if M < yi else "Ping" if M == yi else "Gai",
    "Cong" if M < bing else "Ping" if M == bing else "Gai",
    ))
