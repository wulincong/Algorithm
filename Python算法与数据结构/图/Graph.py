
class Vertex:
    
    def __init__(self, key):
        self.id = key
        self.connectedTo = {}

    def addNeighbor(self, nbr, weight = 0):
        self.connectedTo[nbr] = weight

    def __str__(self):
        return str(self.id) + 'connectedTo' + str([x.id for x in self.connectedTo])
    
    def getConnections(self):
        return self.connectedTo.keys()

    def getId(self):
        return self.id

    def getWeight(self, nbr):
        return self.connectedTo[nbr]


class Graph:
    
    def __init__(self):
        self.verList = {}
        self.numVertices = 0

    def addVertex(self, key):
        '''增加一个顶点'''
        self.numVertices = self.numVertices + 1
        newVertex = Vertex(key)
        self.verList[key] = newVertex
        return newVertex

    def getVertex(self, n):
        '''返回图中所有的顶点'''
        if n in self.verList:
            return self.verList[n]
        else:
            return None

    def __contains__(self, n):
        return n in self.verList

    def addEdge(self, f, t, cost = 0):
        '''增加一个边f->t'''
        if f not in self.verList:
            self.addVertex(f)
        if t not in self.verList:
            self.addVertex(t)
        self.verList[f].addNeighbor(self.verList[t], cost)
    
    def getVertex(self):
        return self.verList.keys()

    def __iter__(self):
        return iter(self.verList.values())

class PriorityQueue:
    def __init__(self):
        pass

def dijkstra(aGraph, start):
    pq = PriorityQueue
    start.setDistance(0)
    


if __name__ == '__main__':
    g = Graph()
    for i in range(6):
        g.addVertex(i)
    print(g.verList)

    g.addEdge(0, 1, 5)
    g.addEdge(0, 5, 2)
    g.addEdge(1, 2, 4)
    g.addEdge(2, 3, 9)
    g.addEdge(3, 4, 7)
    g.addEdge(3, 5, 3)
    g.addEdge(4, 0, 1)
    g.addEdge(5, 4, 8)
    g.addEdge(5, 2, 1)

    for v in g:
        for w in v.getConnections():
            print("(%s, %s)"%(v.getId(), w.getId()))
