class Solution:
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0:
            return 0
        elif len(nums) == 1:
            return nums[0]
        
        pp_pre = nums[0]
        p_pre = pp_pre if pp_pre > nums[1] else nums[1]
        result = p_pre
        
        for i in range(2, len(nums)):
            result1 = pp_pre + nums[i]
            result = result1 if result1 > p_pre else p_pre
            pp_pre, p_pre = p_pre, result
        
        return result
