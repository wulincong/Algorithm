A, B = input().split(" ")
A = int(A)
B = int(B)

C = A + B

C_str = str(C)
S_tmp = ""
flag = 0

for i in range(len(C_str), 0, -1): 
    if(flag != 3):
        flag += 1
    else:
        flag = 0
        S_tmp += ","
    S_tmp += C_str[i - 1]
    
print(S_tmp[::-1])
