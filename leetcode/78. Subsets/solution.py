class Solution:
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        elem_num = len(nums)
        subset_num = pow(2, elem_num)
        ret = [[] for _ in range(subset_num)]

        for i in range(elem_num):
            for j in range(subset_num):
                if (j >> i) & 1:
                    ret[j].append(nums[i])

        return ret


def main():
    so = Solution()
    nums = [1, 2, 3]
    print(so.subsets(nums))

if __name__ == "__main__":
    main()