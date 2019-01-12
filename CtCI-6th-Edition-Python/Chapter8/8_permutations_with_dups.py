# 列出字符串的全排列，字符串可以包含重复字符
# 解法二，也就是交换的方法，在这里不好用。因为比如，cbaa，我们固定c对b及其
# 之后的a进行交换，会得到两个caab。

def permutations(string):
    return partial_permutations("", sorted(string))

def partial_permutations(partial, letters):
    if len(letters) == 0:
        return [partial]
    permutations = []
    previous_letter = None
    for i, letter in enumerate(letters):
        if letter == previous_letter:
            continue
        next_partial = partial + letter
        next_letters = letters[:i] + letters[(i+1):]
        permutations += partial_permutations(next_partial, next_letters)
        previous_letter = letter
    return permutations


def permutations1(chars):
    if chars == None:
        return None
    elif len(chars) == 0:
        return [""]
    return permutations1_helper(chars, 0)

def permutations1_helper(chars, begin):
    permutations = []
    if begin == (len(chars) - 1):
        return ["".join(chars)]
    else:
        for i in range(begin, len(chars)):
            if chars[begin] == chars[i] and begin != i:
                continue
            chars[begin], chars[i] = chars[i], chars[begin]
            permutations += permutations1_helper(chars, begin + 1)
            chars[begin], chars[i] = chars[i], chars[begin]
    return permutations

import unittest

class Test(unittest.TestCase):
    def test_permutations(self):
        self.assertEqual(permutations("abca"), ["aabc", "aacb", "abac", "abca",
            "acab", "acba", "baac", "baca", "bcaa", "caab", "caba", "cbaa"])
        self.assertEqual(permutations("ABCD"), ["ABCD", "ABDC", "ACBD", "ACDB",
            "ADBC", "ADCB", "BACD", "BADC", "BCAD", "BCDA", "BDAC", "BDCA",
            "CABD", "CADB", "CBAD", "CBDA", "CDAB", "CDBA", "DABC", "DACB",
            "DBAC", "DBCA", "DCAB", "DCBA"])
    # def test_permutations1(self):
    #     self.assertEqual(sorted(permutations1(list("abca"))), ["aabc", "aacb", "abac", "abca",
    #         "acab", "acba", "baac", "baca", "bcaa", "caab", "caba", "cbaa"])
    #     self.assertEqual(sorted(permutations1(list("ABCD"))), ["ABCD", "ABDC", "ACBD", "ACDB",
    #         "ADBC", "ADCB", "BACD", "BADC", "BCAD", "BCDA", "BDAC", "BDCA",
    #         "CABD", "CADB", "CBAD", "CBDA", "CDAB", "CDBA", "DABC", "DACB",
    #         "DBAC", "DBCA", "DCAB", "DCBA"])

if __name__ == "__main__":
    unittest.main()
