from functools import cmp_to_key

class Solution:
    def largestNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """
        def cmp(a, b):
            sa = str(a)
            sb = str(b)
            ab = sa + sb
            ba = sb + sa
            if ab > ba:
                return -1
            elif ab > ba:
                return 0
            else:
                return 1
        key = cmp_to_key(cmp)
        nums = sorted(nums, key=key)

        return "".join(str(i) for i in nums).lstrip('0') or '0'

def main():
    so = Solution()
    nums = [0, 0, 0]
    print(so.largestNumber(nums))

if __name__ == "__main__":
    main()