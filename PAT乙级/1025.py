'''
1025 反转链表 (25 分)
 给定一个常数 K 以及一个单链表 L，请编写程序将 L 中每 K 个结点反转。例如：给定 L 为 1→2→3
 →4→5→6，K 为 3，则输出应该为 3→2→1→6→5→4；如果 K 为 4，则输出应该为 4→3→2→1→5→6，即最后
 不到 K 个元素不反转。

输入格式：
 每个输入包含 1 个测试用例。每个测试用例第 1 行给出第 1 个结点的地址、结点总个数正整数 N 
 (≤10^5)、以及正整数 K (≤N)，即要求反转的子链结点的个数。结点的地址是 5 位非负整数，NULL 
 地址用 −1 表示。

 接下来有 N 行，每行格式为：
 Address Data Next
 其中 Address 是结点地址，Data 是该结点保存的整数数据，Next 是下一结点的地址。

输出格式：
 对每个测试用例，顺序输出反转后的链表，其上每个结点占一行，格式与输入相同。
'''
first, N, K = input().split(" ")
N = int(N)
K = int(K)
dic = {}
l = []
n = N
while n:
    n -= 1
    addr, data, next = input().split(" ")
    dic[addr] = [data, next]

cur = first
while cur != '-1':
    l.append(cur)
    cur = dic[cur][1]

i = 1
while K*i < len(l):
    l[(i-1)*K:i*K] = reversed(l[(i-1)*K:i*K])
    i += 1

for i, e in enumerate(l):
    print("{} {} {}".format(e, dic[e][0], l[i+1] if i+1 < N else -1))

