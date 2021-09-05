M = int(input())
l = [int(_) for _ in input().split(" ")]
for i in l:
    for N in range(10):
        res = str(N * i ** 2)
        if res.endswith(str(i)):
            print("{} {}".format(N, res))
            break
    else:
        print("No")
