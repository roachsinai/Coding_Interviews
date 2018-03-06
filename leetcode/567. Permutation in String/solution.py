class Solution:
    def checkInclusion(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        
        num_s1 = [ord(x) - ord('a') for x in s1]
        num_s2 = [ord(x) - ord('a') for x in s2]
        len1 = len(s1)

        target = [0] * 26
        for x in num_s1:
            target[x] += 1
        
        window = [0] * 26
        for i, x in enumerate(num_s2):
            window[x] += 1
            if i >= len1:
                window[num_s2[i-len1]] -= 1 # 保证window中只有len1个1
            if window == target:
                return True
        return False