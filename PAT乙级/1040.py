'''
1040 有几个PAT (25 分)
 字符串 APPAPT 中包含了两个单词 PAT，其中第一个 PAT 是第 2 位(P)，第 4 位(A)，
 第 6 位(T)；第二个 PAT 是第 3 位(P)，第 4 位(A)，第 6 位(T)。

 现给定字符串，问一共可以形成多少个 PAT？

输入格式：
 输入只有一行，包含一个字符串，长度不超过10^5，只包含 P、A、T 三种字母。

输出格式：
 在一行中输出给定字符串中包含多少个 PAT。由于结果可能比较大，只输出对 1000000007 
 取余数的结果。
'''

s = list(input())
P = []
A = []
T = []
for i, e in enumerate(s):
    if e == 'P': P.append(i)
    elif e == 'A': A.append(i)
    elif e == 'T': T.append(i)

# print(P)
# print(A)
# print(T)
cnt = 0
while P:
    p = P.pop()
    j = -1  # A的指针
    while A[j] > p:
        k = -1
        while T[k] > A[j]:
            cnt += 1
            k -= 1
            if( -k > len(T)): break
        j -= 1


print(cnt)







