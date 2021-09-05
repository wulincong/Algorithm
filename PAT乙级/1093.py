A_s = input()
B_s = input()
A = set(A_s)
B = set(B_s)

s = set()
a_b = list(A | B)
is_output = {i:0 for i in a_b}

for i in A_s+B_s:
    if i in a_b:
        if not is_output[i]:
            print(i, end="")
            is_output[i] = 1





