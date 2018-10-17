// 可以买入卖出k次，那么最多可以赚多少钱？
//
// 一般的动态规划的思想，在到第i天进行j次交易赚的钱应该满足这样的递推方程：
// profit[i][j] = max( profit[i-1][j], profit[i-1][j-1]+diff )，其中，diff = price[i]-price[i-1];
//
// 但是，这样有一个问题就是如果你前一天买入卖出一次赚了，今天买入卖出一次也赚了，那么这两次其实可以合并为一次！比如3天的股票价格如下：1 3 9；那只需第一天买入，最后一天卖出即可。
//
// 那么，定义一个数组local[][]表示到第i天进行的j次交易中肯定有一次交易（至少一次卖出，可以是当天买当天卖收益为0，也可以是diff）的最优解，而定义global[i-1][j]则是到第i天共j次交易的最优解。
//
// 那么：
// local[i][j] = max(global[i-1][j-1], local[i-1][j]+diff)
// global[i][j] = max(local[i][j], global[i-1][j])
//
// 第一个公式表明：如果diff>0，那么可以将i-1天买入i天卖出和i-1天的交易（对local来说，local代表每天至少一次不亏的交易）合并为一次交易；否则，局部最优解等于前一天j-1次交易的解加上在第i天直接买入卖出一次的值（diff=0)。
// 第二个公式表明：全局最优解即相同买入卖出次数情况下，前一天所有交易的最优解和当天所有交易的局部最优解最大值（因为一天其实只能赚一次，然后在这一天不论买入卖出多少次diff=0）。
//
// local[n][k+1],那么local[0][*]=0，即第一天交易多少次收入都是0；global一样；
// local[*][0]=0，即不论到第几天，不进行交易收益都是0；

// 1 7 2 6 3 5 8 需要 4 次交易 就可以通过动态规划得到 交易任意多次的最大收益（类似第二题）,那么这种情况下就直接使用题二的方法求解
// 7 6 5 4 3 1 2 则只需要 1 次交易

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n < 2)
            return 0;
        if (k > n/2)
            return maxProfit(prices); // 第二题的方式求解，避免内存不足

        int local[n][k+1];
        int global[n][k+1];
        for (int i = 0; i < n; ++ i)
        {
            local[i][0] = 0;
            global[i][0] = 0;
        }
        for (int i = 0; i < k+1; ++ i)
        {
            local[0][i] = 0;
            global[0][i] = 0;
        }

        for (int i = 1; i < prices.size(); ++ i)
        {
            int diff = prices[i] - prices[i-1];
            for (int j = 1; j <= k; ++ j)
            {
                local[i][j] = max(local[i-1][j]+diff, global[i-1][j-1]);
                global[i][j] = max(global[i-1][j], local[i][j]);
            }
        }

        return global[n-1][k];
    }

        return [n-1][k];
    }


    int maxProfit(vector<int>& prices) {
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

    return 0;
}

// References： http://liangjiabin.com/blog/2015/04/leetcode-best-time-to-buy-and-sell-stock.html
