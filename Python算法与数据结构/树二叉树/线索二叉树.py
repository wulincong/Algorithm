线索 = 1
孩子 = 0
空 = None
不等 = lambda x,y: x!=y

class 线索树:
    数据 = None
    左孩子 = None
    右孩子 = None
    左标志 = 孩子
    右标志 = 孩子

    def __init__(self, 数据):
        self.数据 = 数据 
    
    def 前驱(self):
        return self.左孩子

    def 后继(self):
        return self.右孩子


def 中序线索(当前节点:线索树, 上一个节点:线索树):
    if(不等(当前节点, 空)):
        中序线索(当前节点.左孩子, 上一个节点)
        if(当前节点):
            pass




