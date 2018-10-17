class Solution(object):
    def findLUSlength(self, strs):
        """
        :type strs: List[str]
        :rtype: int
        """
        # 判断s是不是t的子串
        def issubsequence(s, t):
            t = iter(t)
            return all(c in t for c in s)

        for s in sorted(strs, key=len, reverse=True):
            if sum(issubsequence(s, t) for t in strs) == 1:
                return len(s)
        return -1
