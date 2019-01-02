# 给定一个二叉树，每个结点有不同权值。输出所有权值和为目标值的路径。
# 路径起点不必为根节点，路径终点不必为叶子节点。结点权值可正可负。

# 思路：目标权重为target_sum，根结点的权重为root.data，那么经过更
# 结点之后的目标权重更新为target_sum - root.data。而什么时候目标权重
# 变为了0，说明找到了一条路径。然后遍历根结点的左右子树，而此时的目标
# 权重包括target_sum和target_sum - root.data。

def paths_with_sum(binary_tree, target_sum):
    partial_paths = ListDict({target_sum: [[]]}) # [[]]允许结点值为0，[]结点值不能为0
    return paths_with_partial_sum(binary_tree, target_sum, partial_paths)


def paths_with_partial_sum(node, target_sum, partial_paths):
    if not node:
        return []
    next_partial_paths = ListDict({target_sum: [[]]})
    for path_sum, paths in partial_paths.items():
        for path in paths:
            next_partial_paths[path_sum - node.value] += [path + [node.name]]
    paths = next_partial_paths[0]
    for child in [node.left, node.right]:
        paths += paths_with_partial_sum(child, target_sum, next_partial_paths)
    return paths


class Node(object):

    def __init__(self, name, value, left=None, right=None):
        self.name, self.value, self.left, self.right = name, value, left, right


class ListDict(dict):

    def __missing__(self, key):
        return []

import unittest

class Test(unittest.TestCase):

    def test_paths_with_sum(self):
        bt=Node("A",4,Node("B",-2,Node("D",7),Node("E", 4)),
                      Node("C", 7,Node("F",-1,Node("H",-1),Node("I",2,Node("K",1))),
                                  Node("G", 0,None,        Node("J", -2))))
        self.assertEqual(paths_with_sum(bt, 12), [["A", "C", "F", "I"]])
        self.assertEqual(paths_with_sum(bt, 2), [["A", "B"], ["B", "E"], ["I"],
            ["F", "I", "K"]])
        self.assertEqual(paths_with_sum(bt, 9), [["A","B","D"], ["A","C","F","H"],
            ["C","F","I","K"], ["A","C","G","J"]])

if __name__ == "__main__":
    unittest.main()

