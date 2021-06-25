class LCS():
    LEFT_UP = '↖'
    UP = '↑'
    LEFT = '←'

    def __init__(self, str_X, str_Y):
        self.x = str_X
        self.y = str_Y
        self.m = len(str_X) + 1
        self.n = len(str_Y) + 1
        self.b = [[0 for _ in range(self.n)] for _ in range(self.m)]
        self.c = [[0 for _ in range(self.n)] for _ in range(self.m)]

    def LCS(self):
        for i in range(1, self.m):
            for j in range(1, self.n):
                if(self.x[i - 1] == self.y[j - 1]): 
                    self.c[i][j] = self.c[i-1][j-1] + 1
                    self.b[i][j] = self.LEFT_UP
                elif(self.c[i - 1][j] >= self.c[i][j - 1]):
                    self.c[i][j] = self.c[i - 1][j]
                    self.b[i][j] = self.UP
                else:
                    self.c[i][j] = self.c[i][j-1]
                    self.b[i][j] = self.LEFT
    
    def show_map(self):
        print("b\n")
        for row in range(self.m ):
            print(" ".join(map(lambda x: str(x), self.b[row])))
        print("c\n")
        for row in range(self.m ):
            print(" ".join(map(lambda x: str(x), self.c[row])))


if __name__ == '__main__':
    L = LCS("ABCBDAB","BDCABA")
    L.LCS()
    L.show_map()
