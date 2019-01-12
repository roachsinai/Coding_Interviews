# 没有重复字母的quanpailie

def permutations(string):
    return partial_permutations("", string)

def partial_permutations(partial, letters_left):
    if len(letters_left) == 0:
        return [partial]
    permutations = []
    for i, letter in enumerate(letters_left):
        next_letters_left = letters_left[:i] + letters_left[(i+1):]
        permutations += partial_permutations(partial + letter, next_letters_left)
    return permutations


def permutations1(string):
    if string == None:
        return None
    permutations = []
    if len(string) == 0:
        permutations.append("")
        return permutations

    first = string[0]
    remainder = string[1:]
    words = permutations1(remainder)
    for word in words:
        for j in range(len(word) + 1):
            permutations.append("".join([word[:j], first, word[j:]]))
    return permutations


def permutations2(chars):
    if chars == None:
        return None
    elif len(chars) == 1:
        return chars
    return permutations2_helper(chars, 0)

def permutations2_helper(chars, begin):
    permutations = []
    if begin == (len(chars) - 1):
        return ["".join(chars)]
    else:
        for i in range(begin, len(chars)):
            chars[begin], chars[i] = chars[i], chars[begin]
            permutations += permutations2_helper(chars, begin + 1)
            chars[begin], chars[i] = chars[i], chars[begin]
    return permutations


import unittest


class Test(unittest.TestCase):
    def test_permutations(self):
        self.assertEqual(permutations("ABCD"), ["ABCD", "ABDC", "ACBD", "ACDB",
            "ADBC", "ADCB", "BACD", "BADC", "BCAD", "BCDA", "BDAC", "BDCA",
            "CABD", "CADB", "CBAD", "CBDA", "CDAB", "CDBA", "DABC", "DACB",
            "DBAC", "DBCA", "DCAB", "DCBA"])
    def test_permutations1(self):
        self.assertEqual(sorted(permutations1("ABCD")), ["ABCD", "ABDC", "ACBD", "ACDB",
            "ADBC", "ADCB", "BACD", "BADC", "BCAD", "BCDA", "BDAC", "BDCA",
            "CABD", "CADB", "CBAD", "CBDA", "CDAB", "CDBA", "DABC", "DACB",
            "DBAC", "DBCA", "DCAB", "DCBA"])
    def test_permutations2(self):
        self.assertEqual(sorted(permutations2(list("ABCD"))), ["ABCD", "ABDC", "ACBD", "ACDB",
            "ADBC", "ADCB", "BACD", "BADC", "BCAD", "BCDA", "BDAC", "BDCA",
            "CABD", "CADB", "CBAD", "CBDA", "CDAB", "CDBA", "DABC", "DACB",
            "DBAC", "DBCA", "DCAB", "DCBA"])

if __name__ == "__main__":
    unittest.main()
