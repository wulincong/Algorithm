set_vaild = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 
    '.'
}

def pw_isvaild(line):

    flag_num = 0
    flag_alpha = 0
    if len(line) < 6:
        print("Your password is tai duan le.")
        return
    for i in line:
        if not i in set_vaild:
            print("Your password is tai luan le.")
            return
        if i.isdigit(): flag_num = 1
        if i.isalpha(): flag_alpha = 1

    if flag_num == 0 and flag_alpha == 1:
        print("Your password needs shu zi.")
        return
    if flag_num == 1 and flag_alpha == 0:
        print("Your password needs zi mu.")
        return
    print("Your password is wan mei.")

if __name__ == '__main__':
    N = int(input())
    while N:
        N -= 1
        pw = input()
        pw_isvaild(pw)
