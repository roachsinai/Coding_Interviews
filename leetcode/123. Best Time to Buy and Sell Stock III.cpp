// 最多可以买入卖出两次，求最大收益

// 因为不能同时持有两张股票，那么肯定是在某天之前买入卖出一次，再某天之后买入卖出一次
// 根据以哪一天为分割分成不同的情况，求所有情况的最大值

#include <algorithm>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2)
            return 0;

        vector<int> pre_profit(n, 0);
        vector<int> post_profit(n, 0);

        int min_price = prices[0];
        for (int i = 1; i < n; ++ i)
        {
            min_price = min(min_price, prices[i]);
            pre_profit[i] = max(pre_profit[i-1], prices[i]-min_price);
        }
        int max_profit = pre_profit[n-1];

        int max_price = prices[n-1];
        for (int i = n-2; i >= 0; -- i)
        {
            max_price = max(max_price, prices[i]);
            post_profit[i] = max(post_profit[i+1], max_price-prices[i]);

            max_profit = max(max_profit, pre_profit[i]+post_profit[i]);
        }

        return max_profit;
    }
};
