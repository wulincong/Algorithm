'''
1035 插入与归并 (25 分)
 根据维基百科的定义：
 插入排序是迭代算法，逐一获得输入数据，逐步产生有序的输出序列。每步迭代中，算法从输入序列中
 取出一元素，将之插入有序序列中正确的位置。如此迭代直到全部元素有序。
 归并排序进行如下迭代操作：首先将原始序列看成 N 个只包含 1 个元素的有序子序列，然后每次迭代
 归并两个相邻的有序子序列，直到最后只剩下 1 个有序的序列。
 现给定原始序列和由某排序算法产生的中间序列，请你判断该算法究竟是哪种排序算法？

输入格式：
 输入在第一行给出正整数 N (≤100)；随后一行给出原始序列的 N 个整数；最后一行给出由某排序算法
 产生的中间序列。这里假设排序的目标序列是升序。数字间以空格分隔。

输出格式：
 首先在第 1 行中输出Insertion Sort表示插入排序、或Merge Sort表示归并排序；然后在第 2 行中
 输出用该排序算法再迭代一轮的结果序列。题目保证每组测试的结果是唯一的。数字间以空格分隔，且
 行首尾不得有多余空格。
'''

array = []
array2 = []

def insert_sort(arr_tmp):
    for i in range(0, len(arr_tmp)):
        if(array2[:i] != sorted(array2[:i])):
            arr_tmp[:i] = sorted(arr_tmp[:i])
            print("Insertion Sort")
            arr_tmp = [str(i) for i in arr_tmp]
            print(" ".join(arr_tmp))
            break
    ...

def is_merge():
    i = 2
    flag = 0
    while i < len(array):
        j = 0
        while j * i < len(array):
            array[i*j:i*(j+1)] = sorted(array[i*j:i*(j+1)])
            j += 1
        if flag:
            arr = [str(i) for i in array]
            print(" ".join(arr))
            return True
        if array == array2: 
            print("Merge Sort")
            flag = 1
        i = i * 2
    return False

if __name__ == '__main__':
    N = int(input())
    array = [int(_) for _ in input().split(" ")]
    array2 = [int(_) for _ in input().split(" ")]
    arr_tmp = array.copy()
    if(not is_merge()):
        insert_sort(arr_tmp)

