'''
1075 链表元素分类 (25 分)
 给定一个单链表，请编写程序将链表元素进行分类排列，使得所有负值元素都排在非负值元素
 的前面，而 [0, K] 区间内的元素都排在大于 K 的元素前面。但每一类内部元素的顺序是不
 能改变的。例如：给定链表为 18→7→-4→0→5→-6→10→11→-2，K 为 10，则输出应该为 -4→
 -6→-2→7→0→5→10→18→11。

输入格式：
 每个输入包含一个测试用例。每个测试用例第 1 行给出：第 1 个结点的地址；结点总个数，
 即正整数N (≤10^5)；以及正整数K (≤10^3)。结点的地址是 5 位非负整数，NULL 地址
 用 −1 表示。

 接下来有 N 行，每行格式为：

 Address Data Next
 其中 Address 是结点地址；Data 是该结点保存的数据，为 [−10^5,10^5] 区间内的整数；
 Next 是下一结点的地址。题目保证给出的链表不为空。

输出格式：
 对每个测试用例，按链表从头到尾的顺序输出重排后的结果链表，其上每个结点占一行，格式
 与输入相同。

'''

first, N, K = input().split(" ")
N = int(N)
K = int(K)
dic = {}
negative = []
less_tk = []
others = []
n = N
while n:
    address, data, next = input().split(" ")
    data = int(data)
    dic[address] = [data, next]
    n -= 1
next = first
while next != '-1':
    address = next
    data, next = dic[next]
    if data < 0: negative.append(address)
    elif data <= K: less_tk.append(address)
    else: others.append(address)

print(negative, less_tk, others)