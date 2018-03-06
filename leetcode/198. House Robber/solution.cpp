// 类似动态规划的思想
// 最优子结构，偷不偷第i个房子，仅由偷完前i-2和偷完前i-1个房子，以及第i个房子的价值决定。

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        else if (nums.size() == 1)
            return nums[0];
            
        int pp_pre = nums[0];
        int p_pre = (nums[0] > nums[1] ? nums[0] : nums[1]);
        int result = p_pre;
        
        for (int i = 2; i < nums.size(); ++ i)
        {
            result = ((pp_pre + nums[i] > p_pre) ? (pp_pre+nums[i]) : p_pre); // 这样也不会选中相邻的房子
            pp_pre = p_pre;
            p_pre = result;
        }
        
        return result;
    }
};