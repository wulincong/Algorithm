'''
1068 万绿丛中一点红 (20 分)

对于计算机而言，颜色不过是像素点对应的一个 24 位的数值。现给定一幅分辨率为 M×N 的画，
要求你找出万绿丛中的一点红，即有独一无二颜色的那个像素点，并且该点的颜色与其周围 8 个
相邻像素的颜色差充分大。

输入格式：
输入第一行给出三个正整数，分别是 M 和 N（≤ 1000），即图像的分辨率；以及 TOL，是所求
像素点与相邻点的颜色差阈值，色差超过 TOL 的点才被考虑。随后 N 行，每行给出 M 个像素的
颜色值，范围在 [0,224) 内。所有同行数字间用空格或 TAB 分开。

输出格式：
在一行中按照 (x, y): color 的格式输出所求像素点的位置以及颜色值，其中位置 x 和 y 分
别是该像素在图像矩阵中的列、行编号（从 1 开始编号）。如果这样的点不唯一，则输出 Not Un
ique；如果这样的点不存在，则输出 Not Exist。
'''



M, N, TOL = [int(_) for _ in input().split(" ")]
Array = []
res = []
n = N
while n:
    n-=1
    Array.append([int(_) for _ in input().split()])

for i in range(1, N-1):
    for j in range(1, M-1):
        if(
            Array[i][j] - Array[i-1][j-1]   > TOL and\
            Array[i][j] - Array[i-1][j]     > TOL and\
            Array[i][j] - Array[i-1][j+1]   > TOL and\
            Array[i][j] - Array[i][j-1]     > TOL and\
            Array[i][j] - Array[i][j+1]     > TOL and\
            Array[i][j] - Array[i+1][j-1]   > TOL and\
            Array[i][j] - Array[i+1][j]     > TOL and\
            Array[i][j] - Array[i+1][j+1]   > TOL
            ):
            res.append((str(j+1), str(i+1), str(Array[i][j])))
# print(res)
if len(res) == 1:
    print("({}, {}): {}".format(res[0][0], res[0][1], res[0][2]))
elif len(res) == 0:
    print("Not Exist")
else:
    print("Not Unique")



