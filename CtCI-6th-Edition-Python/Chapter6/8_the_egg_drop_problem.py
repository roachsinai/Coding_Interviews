#

import functools


@functools.lru_cache(maxsize=None)
def f(h, m):
    if h == 0:
        return 0
    if m == 1:
        return h

    res = min([max([f(i - 1, m - 1), f(h - i, m)])
               for i in range(1, h + 1)]) + 1
    return res

import unittest

class Test(unittest.TestCase):
    def test_egg_drop_floor(self):
        self.assertEqual(f(100, 2), 14)
        self.assertEqual(f(200, 2), 20)

if __name__ == "__main__":
    unittest.main()

