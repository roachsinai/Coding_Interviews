class Solution:
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        if  len(nums) == 1:
            return nums[0]
        
        ret, pre_max_mul, pre_min_mul, = nums[0], nums[0], nums[0]
        for i in range(1, len(nums)):
            max_mul = max(max(pre_max_mul * nums[i], pre_min_mul * nums[i]), nums[i])
            min_mul = min(min(pre_max_mul * nums[i], pre_min_mul * nums[i]), nums[i])
            pre_max_mul = max_mul
            pre_min_mul = min_mul
            ret = max(max_mul, ret)
        
        return ret