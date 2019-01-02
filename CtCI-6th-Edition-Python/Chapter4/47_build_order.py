# 给定一系列项目，和项目之间的依赖关系，输出完成所有项目的顺序，不能输出Error
# 依赖中，括号里面第二项依赖第一项
# Input:
#     projects: a, b, c, d, e, f
#     dependencies: (a, d), (f, b), (b, d), (f, a), (d, c)
# Output: f, e, a, b, d, c

def build_order(projects, dependencies):
    nodes = {}
    for project in projects:
        nodes[project] = GraphNode(project)
    for dependency in dependencies:
        nodes[dependency[0]].add_edge(nodes[dependency[1]])
    q = Queue()
    for project in projects:
        node = nodes[project]
        if not node.dependencies_left:
            q.put(node)
    build_order = []
    while q.is_not_empty():
        node = q.get()
        build_order.append(node.data)
        for dependent in node.edges:
            dependent.dependencies_left -= 1
            if not dependent.dependencies_left:
                q.put(dependent)
    if len(build_order) < len(projects):
        return Exception("Cycle detected")
    return build_order



class GraphNode():
    def __init__(self, data):
        self.data = data
        self.edges = []
        self.dependencies_left = 0

    def add_edge(self, node):
        self.edges.append(node)
        node.dependencies_left += 1


class Queue():
    def __init__(self):
        self.array = []

    def put(self, item):
        self.array.append(item)

    def get(self):
        return self.array.pop(0)

    def is_not_empty(self):
        return len(self.array) > 0


import unittest

class Test(unittest.TestCase):
    def test_build_order(self):
        projects = ["A", "B", "C", "D", "E", "F", "G"]
        dependencies1 = [("C", "A"), ("B", "A"), ("F", "A"), ("F", "B"), ("F", "C"),
            ("A", "E"), ("B", "E"), ("D", "G")]
        self.assertEqual(build_order(projects, dependencies1),
            ["D", "F", "G", "B", "C", "A", "E"])
        dependencies2 = [("A", "B"), ("B", "C"), ("C", "D"), ("D", "A")]
        self.assertEqual(build_order(projects, dependencies2).__class__, Exception)
        dependencies3 = [("A", "B"), ("A", "C"), ("E", "A"), ("E", "B"), ("A", "F"),
            ("B", "F"), ("C", "F"), ("G", "D")]
        self.assertEqual(build_order(projects, dependencies3),
            ["E", "G", "A", "D", "B", "C", "F"])

if __name__ == "__main__":
    unittest.main()
