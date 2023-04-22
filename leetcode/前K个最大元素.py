import re
from collections import Counter

def topKFrequent(nums, k):
    counts = Counter(nums)
    return [item[0] for item in counts.most_common(k)]

if __name__ == '__main__':
    # nums = [1,1,1,2,2,3]
    # k = 2
    # res = topKFrequent(nums, k)   # 输出 [1, 2]

    # nums = [1,1,1,2,2,3], k = 2
    s = input()
    nums = list(re.findall("\d+", s))
    k = int(nums[-1])
    nums = nums[:-1]
    res = topKFrequent(nums, k)
    print("[" + ",".join(res)+ "]")