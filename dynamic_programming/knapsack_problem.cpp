// 0-1 背包问题，是说有 N 件物品和容量为 V 的背包，第 i 件物品的价值是 c[i], 容量是 w[i]
// 那么如何装入物品使得背包中最后的物品价值最高呢？

// 另 dp[i][j] 表示再背包容量为 j 时，装入前 i 个物品（有的物品可能没有装入）的最大价值，即最优子结构
// 那么， dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]]+c[i]), 前一种代表在考虑第 i 个物品时，并没有加入背包还是之前 i-1 个物品的最大价值
// 后一种表示加第 i 个物品先加入背包之后前 i-1 个物品可以加入的最大价值
// 需要注意的是：这有可能使得价值下降，加入 i 有可能挤掉某个物品，所以需要比较两值的大小

// 那么， dp[1][j] = max(dp[0][j], dp[0][j-w[0]] + c[0]), j 是内层循环：from 0 to V
// 因为 dp[0][j] 为 0，放 0 个物品， 所以 dp[1][j] = c[0] 这是合理的（背包容量足够，而且只放前 1 个物品）

// 另一个条件，如果当前要放入的物品超过了背包的容量，只能等于 dp[i-1][j]

#include <iostream>

using namespace std;

int max(int a, int b)
{
    return (a > b ? a : b);
}

int knapSack(int W, int* w, int* c, int n)
{
    int dp[n+1][W+1];

    for (int i = 0; i <= n; ++ i)
        for (int j = 0; j <= W; ++ j)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (w[i-1] <= j)
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i-1]]+c[i-1]);
            else
                dp[i][j] = dp[i-1][j];
        }

    return dp[n][W];
}

int main()
{
    int c[] = {60, 100, 120};
    int w[] = {10, 20, 30};
    int  W = 50;
    int n = sizeof(c)/sizeof(c[0]);
    cout << knapSack(W, w, c, n) << endl;

    return 0;
}
