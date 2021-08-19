
class Vertex:

    def __init__(self, name, weight = 0):
        self.name = name
        self.weight = weight
        self.connectedTo = {}
        self.visited = False
    
    def addNeighbor(self, neighbor, weight):
        self.connectedTo[neighbor.name] = neighbor
        self.weight += weight
    
    def __str__(self):
        return self.name

class Graph:

    def __init__(self):
        self.vertexList = {}
        self.numVertices = 0
        

    def addVertex(self, name):
        self.numVertices += 1
        newVertex = Vertex(name)
        self.vertexList[name] = newVertex

    def addRoute(self, a, b, weight):

        if b not in self.vertexList.keys():
            self.addVertex(b)
        if a not in self.vertexList.keys():
            self.addVertex(a)

        self.vertexList[a].addNeighbor(self.vertexList[b], weight)
        self.vertexList[b].addNeighbor(self.vertexList[a], weight)

    def __iter__(self):
        return iter(self.vertexList.values())

def DFS(vertex, Gang:list):
    if(vertex.visited): return
    vertex.visited = True
    Gang.append(vertex)
    for i in vertex.connectedTo.keys():
        DFS(vertex.connectedTo[i], Gang)

if __name__ == '__main__':
    N, K = input().split(" ")
    N = int(N)
    K = int(K)
    G = Graph()
    for i in range(N):
        a, b, weight = input().split(" ")
        weight = int(weight)
        G.addRoute(a, b, weight)
    Gangs = []
    for i in G:
        if not i.visited:
            Gang = []
            DFS(i, Gang)
            print([_.name for _ in Gang])


    for i in G:
        print("{a_name} - {weight}".format(a_name = i.name, weight = i.weight))

