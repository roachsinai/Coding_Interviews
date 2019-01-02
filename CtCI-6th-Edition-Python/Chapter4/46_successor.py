# 找到二叉搜索树中某个结点的下个结点（中序遍历）

def successor(node):
    if not node:
        return None
    child = node.right
    if child:
        while child.left:
            child = child.left
    if child:
        return child
    # node 是最右侧结点
    if node.parent and node.parent.data >= node.data:
        return node.parent
    return None


class Node():
    def __init__(self, data, left=None, right=None):
        self.data, self.left, self.right = data, left, right
        self.parent = None
        if self.left: self.left.parent = self
        if self.right: self.right.parent = self

import unittest

class Test(unittest.TestCase):
    def test_successor(self):
        self.assertEqual(successor(Node(22, Node(11))), None)
        self.assertEqual(successor(Node(22, Node(11), Node(33))).data, 33)
        self.assertEqual(successor(Node(22, Node(11), Node(33, Node(28)))).data, 28)
        self.assertEqual(successor(Node(22, Node(11), Node(33)).left).data, 22)
        self.assertEqual(successor(Node(22, Node(11), Node(33)).right), None)

if __name__ == "__main__":
    unittest.main()


