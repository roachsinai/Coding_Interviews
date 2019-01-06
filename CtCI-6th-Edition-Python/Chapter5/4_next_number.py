# 对于一个数N，将所有和它的二进制表示中1的个数相同的数升序排列，返回与它相邻的两个数

def get_next(n):
    """c0为二进制表示最右端的0的个数，c1为rightmost non-trailing 1的个数"""
    # compute c0 and c1
    c = n
    c0 = c1 = 0
    while (c & 1) == 0 and c != 0:
        c0 += 1
        c >>= 1

    while (c & 1) == 1:
        c1 += 1;
        c >>= 1

    # Error if n == 11..1100..00, there is no bigger number with same number of 1s.
    if (c0 + c1) == 31 or (c0 + c1) == 0:
        return -1

    p = c0 + c1
    n |= (1 << p)
    n &= ~((1 << p) - 1)
    n |= (1 << (c1 - 1)) - 1

    return n


def get_prev(n):
    """c1为二进制表示最右端的1的个数，c0为rightmost non-trailing 0的个数"""
    # compute c0 and c1
    c = n
    c1 = c0 =0
    while (c & 1) == 1:
        c1 += 1
        c >>= 1

    if c == 0:
        return -1

    while (c & 1) == 0 and c != 0:
        c0 += 1
        c >>= 1

    p = c0 + c1
    n &= ((~0) << (p + 1)) # clears from bit p onwards

    mask = (1 << (c1 + 1)) - 1
    n |= mask << (c0 - 1)

    return n


import unittest

class Test(unittest.TestCase):
    def test_next_numbers(self):
        self.assertEqual((get_prev(8),get_next(8)), (4, 16))
        self.assertEqual((get_prev(12),get_next(12)), (10, 17))
        self.assertEqual((get_prev(15),get_next(15)), (-1, 23))
        self.assertEqual((get_prev(143),get_next(143)), (124, 151))
        self.assertEqual((get_prev(159),get_next(159)), (126, 175))

if __name__ == "__main__":
    unittest.main()

