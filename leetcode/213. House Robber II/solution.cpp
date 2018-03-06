// 暴力法，就是循环所有可能得到最大的解

// 实际上在环中的房子，两个相邻的房子在最优解中最后有三种状态：前一个被偷，后一个被偷，两个都没有被偷。
// 这样的话，假如第i个房子不偷，那么i+1个房子可偷可不偷，这就和第一道题一样了。同样，在另第i+1个房子不偷，最优解肯定在这两个结果中。

#include <algorithm>

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        else if (nums.size() == 1)
            return nums[0];
            
        return max( rob(nums, 0, nums.size()-2), rob(nums, 1, nums.size()-1) );
    }
    
    int rob(vector<int>& nums, int begin, int end)
    {
        if (begin == end)
            return nums[begin];
        if (begin == end-1)
            return ((nums[begin] > nums[end]) ? nums[begin] : nums[end]);
            
        int pp_pre = nums[begin], p_pre = max(pp_pre, nums[begin + 1]);
        int result = p_pre;
        
        for (int i = begin + 2; i <= end; ++ i)
        {
            result = ((pp_pre + nums[i] > p_pre) ? (pp_pre+nums[i]) : p_pre);
            pp_pre = p_pre;
            p_pre = result;
        }
        
        return result;
    }
};