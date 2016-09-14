// 求一个字符串中的最长回文字符串的长度

// 当然，可以暴力解法 i 从 0 开始 ++, j 每次都等于 n-1 开始 --, 得到最大长度
// 这样子串有n^2个，子串的平均长度是O(n)，总的时间复杂度是O(N^3)

// 回文字符串肯定是以某个 index 为中心对称，或者以两个相邻（位置）相等（元素）的位置对称
// 这样确定好位置之后，从中心两侧找该中心的最长回文串
// 这样的中心有 n + (n+1) 个, 每个中心的平均比较次数O(n),时间复杂度O(N^2)

// 动态规划
// 定义一个标志数组 dp[][], dp[i][j] 标志 i,j 之间的字符串是不是一个回文串
// dp[i][j] 为 true，有如下情况：
// 1.                                 i == j
// 2. str[i]==str[j],                 j-i = 1
// 3. str[i]==str[j] && dp[i+1][j-1], i-j > 1
// 从递推公式可以看出来，在计算 dp 矩阵的时候，需要先判断长度短的子串是不是回文
// 所以外层循环是，子串的长度，内层是字串开始位置
// 前提：dp[i][i] = true; dp[i][i+1] = (s[i] == s[i+1])

// Manacher's Algorithm

#include <iostream>
#include <string>

using namespace std;

string longestPalindrome(string s)
{
    const int n = s.size();
    bool dp[n][n];
    fill_n(&dp[0][0], n*n, false);

    for (int i = 0; i < n-1; ++ i)
    {
        dp[i][i] = true;
        dp[i][i+1] = (s[i] == s[i+1]);
    }
    dp[n-1][n-1] = true;

    int max_len = 1; // 保存最长回文子串长度
    int start = 0;   // 最长回文子串起点

    for (int len = 3; len <= n; ++ len)
        for (int i = 0; i+len < n; ++ i)
        {
            dp[i][j] = ( dp[i+1][j-1] && s[i]==s[j]);

            if (dp[i][j] && max_len < len)
            {
                max_len = len;
                start = i;
            }
        }

    return s.substr(start, max_len);
}

int main()
{

    return 0;
}
