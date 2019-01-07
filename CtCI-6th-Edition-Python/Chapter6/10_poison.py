# 1000个瓶子其中一个是有毒的，使用10个检测纸，检测出有毒的
# 瓶子。每个检测纸可以涂抹无数次瓶子中的液体，但是只能检测
# 一次。

def detect_poison(bottles, strips):
    for b, bottle in enumerate(bottles):
        for s, strip in enumerate(strips):
            if b & (1 << s):
                strip.add_drop_from(bottle)
    index = 0
    for s, strip in enumerate(strips):
        strip.wait()
        if strip.detect_poison:
            index |= (1 << s)
    return index


class Bottle(object):

    def __init__(self, poison):
        self.poison = poison


class Strip(object):

    def __init__(self):
        self.detect_poison = False
        self.drops_from = []

    def add_drop_from(self, bottle):
        self.drops_from.append(bottle)

    def wait(self):
        for drop in self.drops_from:
            if drop.poison:
                self.detect_poison = True
                return


import unittest

class Test(unittest.TestCase):
    def test_detect_posion(self):
        bottles = [Bottle(ix == 367) for ix in range(1000)]
        strips = [Strip() for i in range(10)]
        self.assertEqual(detect_poison(bottles, strips), 367)

if __name__ == "__main__":
    unittest.main()
