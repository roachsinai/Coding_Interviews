# 跳台阶时，一次可以选择跳1，2，或3个台阶，那么跳n级台阶有多少种跳法

def triple_step(n):
    counts = [1, 1, 2]
    if n < 3:
        return counts[n]
    for i in range(3, n + 1):
        counts[i % 3] = sum(counts)
    return counts[i % 3]


import unittest

class Test(unittest.TestCase):
    def test_triple_step(self):
        self.assertEqual(triple_step(3), 4)
        self.assertEqual(triple_step(7), 44)

if __name__ == "__main__":
    unittest.main()
