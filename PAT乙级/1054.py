def is_number(s):
    try:
        float(s)
        return True
    except ValueError:
        pass

N = int(input())
l = input().split(" ")
num_l = []
for i in l:
    if(is_number(i) and float(i) >= -1000 and float(i) <= 1000\
    and float(i) * 100 - int(float(i)*100) < 0.00001):
        num_l.append(float(i))
    else:
        print("ERROR: {} is not a legal number".format(i))
print("The average of {} numbers is {:.2f}".format(len(num_l), sum(num_l) / len(num_l)))
