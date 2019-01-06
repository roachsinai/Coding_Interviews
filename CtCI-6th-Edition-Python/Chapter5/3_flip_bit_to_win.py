# 给定一个数字，在它对应的二进制位中可以任意反转一个比特位，返回翻转之后
# 连续出现的1的个数，如果全为1可以不反转

def longest_sequence_after_flip(bits):
    bit = 1 << 63
    longest = 0
    current_without_flap = current_with_flap = 0
    while bit:
        if bits & bit:
            current_with_flap += 1
            current_without_flap += 1
        else:
            current_with_flap = current_without_flap + 1
            current_without_flap = 0
        if current_with_flap > longest:
            longest = current_with_flap
        bit >>= 1
    return longest


import unittest

class Test(unittest.TestCase):
    def test_longest_sequence_after_flip(self):
        self.assertEqual(longest_sequence_after_flip(0b1111100), 6)
        self.assertEqual(longest_sequence_after_flip(0b0111111), 7)
        self.assertEqual(longest_sequence_after_flip(-1), 64)
        self.assertEqual(longest_sequence_after_flip(0b1011110111001111110), 8)

if __name__ == "__main__":
    unittest.main()

