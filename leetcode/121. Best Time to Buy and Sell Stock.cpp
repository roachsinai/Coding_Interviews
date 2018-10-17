// 只能买入卖出一次股票，求最大的收益
// 第一次是买入，买入价格应小于卖出价格
// 输入为该股票，每天的价格

// 那需要记录一下当天之前所有天的股票最小值，那么当天的股票价格减去最小值就是当天的最大收益
// 返回所有天的最大收益即可

#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX;
        int max_profit = 0;

        for (int i = 0; i < prices.size(); ++ i)
        {
            if (prices[i] < min_price)
                min_price = prices[i];

            max_profit = max(prices[i] - min_price), max_profit);
        }
        return max_profit;
    }
};
