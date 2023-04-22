from collections import Counter
import re
def find_mode(S):
    # 使用Counter计算每个元素在S中出现的次数
    counts = Counter(S)
    # 找到出现次数最多的元素和它的重数
    mode, mode_count = counts.most_common(1)[0]
    
    print(mode + "\n"+ str(mode_count))

if __name__ == '__main__':
    s = input()
    nums = re.findall(r'\d', s)
    find_mode(nums)