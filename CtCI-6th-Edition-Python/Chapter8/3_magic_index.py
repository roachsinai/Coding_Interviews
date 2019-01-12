# 在一个有序数组中找到一个魔术下标（下标和在该位置存储的值大小相同）如果存在的话
# 这里假设数组中的数不重复

def magic_index_distinct(array):
    if len(array) == 0 or array[0] > 0 or array[-1] < len(array) - 1:
        return None
    return magic_index_distince_bounds(array, 0, len(array) - 1)


def magic_index_distince_bounds(array, start, end):
    if start == end:
        return None
    middle = (start + end) // 2
    if array[middle] == middle:
        return middle
    elif array[middle] > middle:
        return magic_index_distince_bounds(array, start, middle - 1)
    else:
        return magic_index_distince_bounds(array, middle + 1, end)


def magic_index(array):
    index = 0
    while index < len(array):
        if index == array[index]:
            return index
        index = max(array[index], index + 1)
    return None


import unittest

class Test(unittest.TestCase):
    def test_magic_index_distinct(self):
        self.assertEqual(magic_index_distinct([3,4,5]), None)
        self.assertEqual(magic_index_distinct([-2,-1,0,2]), None)
        self.assertEqual(magic_index_distinct([-20,0,1,2,3,4,5,6,20]), None)
        self.assertEqual(magic_index_distinct([-20,0,1,2,3,4,5,7,20]), 7)
        self.assertEqual(magic_index_distinct([-20,1,2,3,4,5,6,20]), 3)

    def test_magic_index(self):
        self.assertEqual(magic_index([3,4,5]), None)
        self.assertEqual(magic_index([-2,-1,0,2]), None)
        self.assertEqual(magic_index([-20,0,1,2,3,4,5,6,20]), None)
        self.assertEqual(magic_index([-20,0,1,2,3,4,5,7,20]), 7)
        self.assertEqual(magic_index([-20,1,2,3,4,5,6,20]), 1)
        self.assertEqual(magic_index([-20,5,5,5,5,5,6,20]), 5)

if __name__ == "__main__":
    unittest.main()
