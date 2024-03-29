'''
1066 图像过滤 (15 分)

图像过滤是把图像中不重要的像素都染成背景色，使得重要部分被凸显出来。
现给定一幅黑白图像，要求你将灰度值位于某指定区间内的所有像素颜色都用一
种指定的颜色替换。

input:输入在第一行给出一幅图像的分辨率，即两个正整数 M 和 N（0<M,N≤500），
另外是待过滤的灰度值区间端点 A 和 B（0≤A<B≤255）、以及指定的替换灰度值。
随后 M 行，每行给出 N 个像素点的灰度值，其间以空格分隔。所有灰度值都在 
[0, 255] 区间内。

output:输出按要求过滤后的图像。即输出 M 行，每行 N 个像素灰度值，每个灰度值
占 3 位（例如黑色要显示为 000），其间以一个空格分隔。行首尾不得有多余空格。
'''

M, N, A, B, G = [int(_) for _ in input().split(" ")]
while M:
    M -= 1
    l = [int(_) for _ in input().split(" ")]
    l = [_ if _ < A or _ > B else G for _ in l ]
    l = ["{:03d}".format(_) for _ in l]
    print(" ".join(l))

