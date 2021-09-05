from collections import Counter

s = input()

Sum = 0

for i in s:
    if i.isalpha():
        i = i.lower()
        Sum += ord(i) - ord('a') + 1

s = "{:b}".format(Sum)
word_counts = Counter(s)
print(word_counts['0'], word_counts['1'])
