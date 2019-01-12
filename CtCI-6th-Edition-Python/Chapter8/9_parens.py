# List all valid strings containing n opening and n closing parenthesis.

def parens1(n):
    """将由0对括号组成的p0、1对括号组成的p1、2对括号组成的p2、3对括号组成的p3，...
    p_n-1对括号组成的都存起来p[n-1]，然后n对括号组成的所有可能的pn=
    [(p0)p_n-1] + [(p1)p_n-2]+ ... + [p1(p_n-2)] + [p0(p_n-1)]"""
    parens_of_length = [[""]]
    if n == 0:
        return parens_of_length[0]
    for length in range(1, n + 1):
        parens_of_length.append([])
        for i in range(length):
            for inside in parens_of_length[i]:
                for outside in parens_of_length[length - i - 1]:
                    parens_of_length[length].append("".join(["(", inside, ")", outside]))
    return parens_of_length[n]


def parens2(open_count=0, close_count=0, memo=None):
    if open_count == 0 and close_count == 0:
        return [""]
    key = (open_count, close_count)
    if memo is None:
        memo = {}
    elif key in memo:
        return memo[key]
    parens = []
    if open_count > 0:
        parens += ["(" + end for end in parens2(open_count-1, close_count, memo)]
    if close_count > open_count:
        parens += [")" + end for end in parens2(open_count, close_count-1, memo)]
    memo[key] = parens
    return parens


def parens3(n):
    return parens_memo3(n, 0, 0, {})

def parens_memo3(n, open_count, close_count, memo):
    if open_count + close_count == 2 * n:
        return [""]
    key = (n - open_count - close_count, open_count)
    if key in memo:
        return memo[key]
    parens = []
    if open_count < n:
        for end in parens_memo3(n, open_count + 1, close_count, memo):
            parens.append("(" + end)
    if close_count < open_count:
        for end in parens_memo3(n, open_count, close_count + 1, memo):
            parens.append(")" + end)
    memo[key] = parens
    return parens


def parens4(n, partial="", open_count=0, close_count=0):
    if open_count + close_count == 2 * n:
        return [partial]
    parens = []
    if open_count < n:
        parens += parens4(n, partial + "(", open_count + 1, close_count)
    if close_count < open_count:
        parens += parens4(n, partial + ")", open_count, close_count + 1)
    return parens


import unittest

class Test(unittest.TestCase):
    def test_parens1(self):
        self.assertEqual(parens1(1), ["()"])
        self.assertEqual(parens1(2), ["()()", "(())"])
        self.assertEqual(parens1(3), ["()()()", "()(())", "(())()", "(()())",
            "((()))"])

    def test_parens2(self):
        self.assertEqual(parens2(1, 1), ["()"])
        self.assertEqual(parens2(2, 2), ["(())", "()()"])
        self.assertEqual(parens2(3, 3), ["((()))", "(()())", "(())()", "()(())",
            "()()()"])
        self.assertEqual(set(parens1(7)), set(parens2(7, 7)))

    def test_parens3(self):
        self.assertEqual(parens3(1), ["()"])
        self.assertEqual(parens3(2), ["(())", "()()"])
        self.assertEqual(parens3(3), ["((()))", "(()())", "(())()", "()(())",
            "()()()"])
        self.assertEqual(set(parens1(7)), set(parens3(7)))

    def test_parens4(self):
        self.assertEqual(parens4(1), ["()"])
        self.assertEqual(parens4(2), ["(())", "()()"])
        self.assertEqual(parens4(3), ["((()))", "(()())", "(())()", "()(())",
            "()()()"])
        self.assertEqual(set(parens1(7)), set(parens4(7)))

if __name__ == "__main__":
    unittest.main()
