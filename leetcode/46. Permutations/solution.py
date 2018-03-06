class Solution:
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        self.pers = []
        self.len = len(nums)
        if not nums:
            return self.pers
        
        self.subpermute(0, nums)
        return self.pers

    def subpermute(self, exchange_point, nums):
        if exchange_point+1 == self.len:
            self.pers.append(nums[:])
        else:
            for i in range(exchange_point, self.len):
                nums[exchange_point], nums[i] = nums[i], nums[exchange_point]
                self.subpermute(exchange_point+1, nums)
                nums[exchange_point], nums[i] = nums[i], nums[exchange_point]


def main():
    nums = [1, 2, 3]
    so = Solution()
    print(sorted(so.permute(nums)))

if __name__ == "__main__":
    main()