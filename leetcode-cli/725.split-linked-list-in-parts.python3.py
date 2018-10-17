# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def splitListToParts(self, root, k):
        """
        :type root: ListNode
        :type k: int
        :rtype: List[ListNode]
        """
        curr, length = root, 0
        while curr:
            curr, length = curr.next, length + 1
        # get the length of each chunk
        chunk_size, longer_chunks_num = length // k, length % k
        res = [chunk_size + 1] * longer_chunks_num + [chunk_size] * (k - longer_chunks_num)
        # split up the list
        prev, curr = None, root
        for index, num in enumerate(res):
            if prev:
                prev.next = None
            res[index] = curr
            for i in range(num):
                prev, curr = curr, curr.next
        return res
