# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from collections import deque

class Solution:
    def preorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        result = []

        if not root:
            return result 
        
        de = deque()
        de.append((root, 1))
        while de:
            node, time = de.pop()
            if time == 1:
                if node.right:
                    de.append((node.right, 1))
                if node.left:
                    de.append((node.left, 1))
                de.append((node, 2))
            else:
                result.append(node.val)
        
        return result
    
    def another_method(self, root):
        stack = []
        result = []

        while root or stack:
            if not root:
                root = stack.pop()
            result.append(root.val)
            if root.right:
                stack.append(root.right)
            root = root.left
        
        return result
