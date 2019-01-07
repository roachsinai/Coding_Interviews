# 100扇门，一个人第一次走过时打开了每一扇门；第二次关闭了为
# 偶数号的门；第三次打开是三的倍数号的门；然后关为四的倍数的
# 门，以此类推。起始时所有的门都是关闭的，求最后打开的门的个
# 数。

# 解法：假设这个人第n次走过一扇门，如果n为门号的约数，则门的
# 状态发生改变。也就是说如果一扇门的门号的约数为奇数，则最后
# 是打开的。
# 另外，当且仅当，一个数为完全平方数时，它的约数个数为奇数。


import math


def lockers_left_open(n):
    return int(math.sqrt(n - 1))


import unittest

class Test(unittest.TestCase):
    def test_lockers_left_open(self):
        self.assertEqual(lockers_left_open(100), 9)
        self.assertEqual(lockers_left_open(200), 14)

if __name__ == "__main__":
    unittest.main()
