# 计算最少经过几次二进制位变换可以把数a变换为数b
# a ^ b就可以得到二者的差异，计算差异中1的个数时可以使用 n & (n - 1)，
# 这个操作每次去掉最右侧的1，总共去了几次说明有几个1

# 如果是一个整数，一个负数异或，得到的是个负数，这样python中由于int的特殊性
# 将会得到无数个1，将其进行转换

# 函数中假定，int是32位的

def bits_different(a, b):
    different = a ^ b
    count = 0
    neg_flag = False
    if different < 0:
        different = abs(different) - 1
        neg_flag = True
    while different:
        different &= (different - 1)
        count += 1

    if neg_flag:
        count = 32 - count
    return count


import unittest

class Test(unittest.TestCase):
    def test_bits_different_1(self):
        self.assertEqual(bits_different(16, 2), 2)
        self.assertEqual(bits_different(17, 34), 4)
        self.assertEqual(bits_different(15, 97), 5)


if __name__ == "__main__":
    unittest.main()

