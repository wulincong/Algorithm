class TreeNode:

    def __init__(self, weight=0, Id=0, children=[], parent=None):
        self.weight = weight
        self.children = children
        self.Id = Id
        self.parent = parent
    def __str__(self):
        return self.weight

    def is_leaf(self):
        return self.children == []
    
    def is_root(self):
        return self.parent is not None

    def sum_weight(self):
        if self.parent:
            return self.parent.sum_weight() + self.weight
        else:
            return self.weight

if __name__ == '__main__':
    TreeList = [TreeNode() for _ in range(100)]
    N, _, W = input().split(" ")
    N = int(N)
    _ = int(_)
    W = int(W)
    weights = input().split(" ")
    for i in range(N):
        TreeList[i].weight = int(weights[i])
        TreeList[i].Id = i
    for i in range(_):
        __ = input().split(" ")
        index = int(__[0])
        Node = TreeList[index]
        children_list = __[2:]
        Node.children = [int(_) for _ in children_list]
        for i in Node.children:
            TreeList[i].parent = Node
    W_list = []
    for i in TreeList:
        if i.is_leaf() and i.sum_weight() == W: 
            p = i
            path_list = []
            while p:  #向上找根节点
                path_list.append(p.weight)
                p = p.parent
            path_list.reverse()
            W_list.append(" ".join([str(_) for _ in path_list]))
    W_list.sort(reverse=True)
    print("\n".join(W_list))






