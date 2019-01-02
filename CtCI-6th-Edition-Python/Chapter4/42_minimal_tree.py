class Node():
    def __init__(self, item):
        self.right = None
        self.left = None
        self.val = item

    def __str__(self):
        return "({}:L V:{} R:{})".format(self.left, self.val, self.right)


def initiate_array_to_binary(array):
    return array_to_binary(array, 0, len(array) - 1)


def array_to_binary(array, start, end):
    if start > end:
        return ''
    mid = (start + end) // 2
    root = Node(array[mid])
    root.left = array_to_binary(array, start, mid - 1)
    root.right = array_to_binary(array, mid + 1, end)
    return root

testArray = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 15, 18, 22, 43, 144, 515, 4123]
print(initiate_array_to_binary(testArray))
