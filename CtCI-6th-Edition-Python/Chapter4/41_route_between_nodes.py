import queue

class Graph():
    def __init__(self):
        self.max_vertices = 6
        self.vertices = [0] * self.max_vertices
        self.count = 0

    def add_node(self, x):
        if self.count < self.max_vertices:
            self.vertices[self.count] = x
            self.count += 1
        else:
            print("Graph full")

    def get_nodes(self):
        return self.vertices

class Node():
    def __init__(self, vertex, adjacent_length):
        self.adjacent = [0] * adjacent_length
        self.vertex = vertex
        self.adjacent_count = 0
        self.visited = False

    def add_adjacent(self, x):
        if self.adjacent_count < len(self.adjacent):
            self.adjacent[self.adjacent_count] = x
            self.adjacent_count += 1
        else:
            print("No more adjacent nodes can be added")

    def get_adjacent(self):
        return self.adjacent

    def get_vertex(self):
        return self.vertex


def breadth_first_search(g, start, end):
    if start == end:
        return True
    q = queue.Queue(len(g.get_nodes()))
    start.visited = True
    q.put(start)
    while not q.empty():
        r = q.get()
        adjacent = r.get_adjacent()
        for i in range(len(adjacent)):
            if adjacent[i].visited == False:
                if adjacent[i] == end:
                    return True
                else:
                    q.put(adjacent[i])
                    adjacent[i].visited = True
    return False


def create_graph():
    g = Graph()
    size_graph = 6
    temp = [0] * size_graph

    temp[0] = Node("a", 3)
    temp[1] = Node("b", 0)
    temp[2] = Node("c", 0)
    temp[3] = Node("d", 1)
    temp[4] = Node("e", 1)
    temp[5] = Node("f", 0)

    temp[0].add_adjacent(temp[1])
    temp[0].add_adjacent(temp[2])
    temp[0].add_adjacent(temp[3])
    temp[3].add_adjacent(temp[4])
    temp[4].add_adjacent(temp[5])

    for i in range(size_graph):
        g.add_node(temp[i])
    return g


g = create_graph()
n = g.get_nodes()
start = n[0]
end =n[5]
print("Start at: {}, End at: {}".format(start.get_vertex(), end.get_vertex()))
print(breadth_first_search(g, start, end))
