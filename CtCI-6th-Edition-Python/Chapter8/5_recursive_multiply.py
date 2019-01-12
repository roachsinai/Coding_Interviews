# 计算两个数相乘的结果，不许使用*, /

# O(log(smaller(a, b)))

def multiply(a, b):
    if a == 0 or b == 0:
        return 0
    flag = True
    if abs(a + b) < abs(a - b):
        flag = False
        if a > 0:
            b = abs(b)
        else:
            a = abs(a)
    smaller = a if a < b else b
    bigger = b if b > a else a
    product = 0
    while smaller:
        bit = smaller & -smaller
        exponent = bit.bit_length() - 1
        product += bigger << exponent
        smaller ^= bit
    if flag:
        return product
    else:
        return -product


def multiply1(a, b):
    if a == 0 or b == 0:
        return 0
    flag = True
    if abs(a + b) < abs(a - b):
        flag = False
        if a > 0:
            b = abs(b)
        else:
            a = abs(a)
    smaller = a if a < b else b
    bigger = b if b > a else a

    product = multiply1_helper(smaller, bigger)
    if flag:
        return product
    else:
        return -product


def multiply1_helper(smaller, bigger):
    if smaller == 0:
        return 0
    elif smaller == 1:
        return bigger

    m = smaller >> 1
    half_product = multiply1_helper(m, bigger)

    if (smaller % 2) == 1:
        return (half_product << 1) + bigger
    else:
        return half_product << 1


import unittest

class Test(unittest.TestCase):
    def test_multiply(self):
        self.assertEqual(multiply(2, 2), 4)
        self.assertEqual(multiply(-1, 125), -125)
        self.assertEqual(multiply(7, 11), 77)
        self.assertEqual(multiply(10000000010, 21), 210000000210)

    def test_multiply1(self):
        self.assertEqual(multiply1(2, 2), 4)
        self.assertEqual(multiply1(-1, 125), -125)
        self.assertEqual(multiply1(7, 11), 77)
        self.assertEqual(multiply1(10000000010, 21), 210000000210)

if __name__ == "__main__":
    unittest.main()
