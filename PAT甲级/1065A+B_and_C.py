T = int(input())

for i in range(T):
    A, B, C = [int(_) for _ in input().split(" ")]
    print("Case #{}: {}".format(i+1, "true" if A + B > C else "false"))
