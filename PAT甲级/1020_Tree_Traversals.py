class TreeNode():

    def __init__(self, data, lchild = None, rchild = None, postOrder = [], inOrder = []):
        self.data = data
        self.lchild = lchild
        self.rchild = rchild
        self.postOrder = postOrder
        self.inOrder = inOrder

    def data(self):
        return self.data

    def lchild(self):
        return self.lchild

    def rchild(self):
        return self.rchild

    def postOrder(self):
        return self.postOrder

    def inOrder(self):
        return self.inOrder


    def unzip(self):
        if(len(self.postOrder) > 1):
            index = self.inOrder.index(self.data)
            lInOrder = self.inOrder[:index]
            rInOrder = self.inOrder[index+1:]
            lPostOrder = self.postOrder[:len(lInOrder)]
            rPostOrder = self.postOrder[len(lInOrder):-1]
            ldata = None if len(lPostOrder) == 0 else lPostOrder[-1]
            rdata = None if len(rPostOrder) == 0 else rPostOrder[-1]
            self.lchild = TreeNode(ldata, postOrder = lPostOrder, inOrder = lInOrder)
            self.rchild = TreeNode(rdata, postOrder = rPostOrder, inOrder = rInOrder)
            self.lchild.unzip()
            self.rchild.unzip()
    
    def levelOrder(self):
        queue = []
        queue.append(self)
        res = []
        while(queue):
            current = queue.pop(0)
            if(current.data):
                res.append(current.data)
            if(current.lchild):queue.append(current.lchild)
            if(current.rchild):queue.append(current.rchild)
        for i in res:
            print(i, end="")
            if i != res[-1]:print(" ", end="")

if __name__ == '__main__':
    input()
    postorder = input().split(" ")
    inorder = input().split(" ")
    root = TreeNode(postorder[-1], postOrder = postorder, inOrder = inorder)
    root.unzip()
    root.levelOrder()




