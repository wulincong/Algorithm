s = input()
lis = [int(_) for _ in s.split(" ")]
arr_sorted = sorted(lis)
n = len(arr_sorted)
if n % 2 == 0:
    median = (arr_sorted[n//2-1] + arr_sorted[n//2]) // 2 + 1
else:
    median = arr_sorted[n // 2]
print(median)