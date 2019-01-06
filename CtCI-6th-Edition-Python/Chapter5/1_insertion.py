# 将数M插入到N的二进制位j和i之间，其中j>i，即j是高位/M为正数。
# M对应的二进制数的长度小于等于(j-i+1)，如果M的长度小于(j-i+1)则在高位补0后插入N中
# M为正数

def insertion(n, m, i, j):
    cleared_n = n & ~((1 << (j+1)) - (1 << i))
    shifted_m = m << i
    return cleared_n | shifted_m


import unittest

class Test(unittest.TestCase):
    def test_insertion(self):
        self.assertEqual(insertion(0b11111111, 0b10, 2, 5), 0b11001011)
        self.assertEqual(insertion(0b00000000, 0b1010, 4, 7), 0b10100000)

if __name__ == "__main__":
    unittest.main()
