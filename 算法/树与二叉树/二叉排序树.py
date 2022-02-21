
class BSTree:
    lchild = None
    rchild = None
    def __init__(self, data = None, parent = None):
        self.data = data
        self.parent = parent
    
    def insert(self, data):
        '''
        二叉排序树的插入
        查询要插入的左孩子或右孩子是否为空，如果为空，对应位置插入值
        如果该插入的节点不空，则向下递归
        '''
        if data == self.data: return
        elif data > self.data:
            if self.rchild == None:
                self.rchild = BSTree(data, self)
                self.rchild.parent = self
            else:
                self.rchild.insert(data)
        elif data < self.data: 
            if self.lchild == None:
                self.lchild = BSTree(data, self)
                self.lchild.parent = self
            else:
                self.lchild.insert(data)

    def search(self, data):
        '''从当前树中查找数据，返回节点
        如果等于当前节点的值，返回当前节点
        如果大于当前节点，查看rchild是否为空，为空则查找失败，不空递归右子树
        如果小于当前节点，查看lchild是否为空，为空则查找失败，不空递归左子树
        '''
        if self.data == data: return self
        if data < self.data:
            if self.lchild == None:
                return False
            else:
                self.lchild.search(data)
        if data > self.data:
            if self.rchild == None:
                return False
            else:
                self.rchild.search(data)

    def is_leaf(self):
        return self.lchild == None and self.rchild == None

    def delete(self, data):
        '''删除节点的操作
        寻找到data节点
            如果节点是叶子节点，可以直接删除
            如果节点只存在左子树，左子树代替本节点
            如果节点只存在右子树，右子树代替本节点
            如果同时存在左右子树，有两种选择
                选择左侧最大的元素代替根节点
                选择右边最大的元素代替根节点
        不是当前节点，递归删除
        '''
        if data == self.data: 
            pass

    def inOrder(self):
        if self.lchild:self.lchild.inOrder()
        print(self.data)
        if self.rchild:self.rchild.inOrder()

    def preOrder(self):
        print(self.data)
        if self.lchild:self.lchild.preOrder()
        if self.rchild:self.rchild.preOrder()


    def postOrder(self):
        if self.lchild: self.lchild.postOrder()
        if self.rchild: self.rchild.postOrder()
        print(self.data)

    def __str__(self):
        if self.lchild:
            return "当前节点{}， 左孩子是{}".format(self.data, self.lchild.data)
        if self.rchild:
            return "当前节点{}， 右孩子是{}".format(self.data, self.rchild.data)
        else: return  "当前节点{}，".format(self.data)

if __name__ == '__main__':
    d = [45, 24, 53, 45, 12, 24, 90]
    root = BSTree(d[0])
    for i in d[1:]:
        root.insert(i)
    # print("preOrder:")
    # root.preOrder()
    # print("inOrder:")
    # root.inOrder()
    # print("postOrder:")
    # root.postOrder()
    print(root.search(45))
