List1 = [
    "S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "S10", "S11", "S12", "S13", \
    "H1", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H10", "H11", "H12", "H13", \
    "C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "C11", "C12", "C13", \
    "D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10", "D11", "D12", "C13", \
    "J1", "J2",
]
# print(len(List2))
def my_answer():
    repeat = int(input())
    shuffling_list = list(map(lambda x :int(x), input().split(" ")))
    # print(shuffling_list)
    sorted_list = List1[:]
    while repeat > 0:
        band_list = zip(sorted_list, shuffling_list)
        sorted_band_list = sorted(band_list, key = lambda x: x[1])
        sorted_list = map(lambda x: x[0], sorted_band_list)
        repeat -= 1
    print(" ".join(sorted_list))


def other_answer():
    try:
        while (1):
            repeat = input()
            numList = map(int, input().split())
            d = List1[:]
            for i in range(repeat):
                b = zip(d, numList)
                c = sorted(b, key=lambda x: x[1])
                d = map(lambda x:x[0], c)
            print (' '.join(d))
    except:
        pass

if __name__ == '__main__':
    my_answer()
