// 这道题就是说你可以无限次的买入卖出股票，但是在再次买入之前必须卖出手里的股票
// 解决方法很直接，但是我想错了。。。只要明天的股票价格比今天的高，就今天买入明天卖出。。。
// 以至于评论区，想到方法的问你们出题的是不是想多了。。。

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0 || prices.size() == 1)
            return 0;

        int max_profit = 0;
        for (int i = 0; i < prices.size()-1; ++ i)
        {
            if (prices[i + 1] > prices[i])
                max_profit += (prices[i+1] - prices[i]);
        }

        return max_profit;
    }
};


int main(int argc, char const *argv[]) {
    vector<int> v(0);

    Solution s;
    cout << s.maxProfit(v) << endl;
    return 0;
}
