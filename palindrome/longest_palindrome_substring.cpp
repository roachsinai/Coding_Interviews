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

//

#include <iostream>
#include <string>

using namespace std;

string longestPalindrome(string s)
{
    const int n = s.size();
    bool bp[n][n];
    fill_n(&dp[0][0], n*n, false);

    int max_len = 1; // 保存最长回文子串长度
    int start = 0;   // 最长回文子串起点

    for (int j = 0; j < n; ++ j)
        for (int i = 0; i < n; ++ i)
        {
            if (j-i < 2)
                dp[i][j] = (s[i] == s[j]);
            else
                dp[i][j] = ( dp[i][j] && s[i]==s[j]);
            if (dp[i][j] && max_len < (j-i+1))
            {
                max_len = j-i+1;
                start = i;
            }
        }

    return s.substr(start, max_len);
}

int main()
{

    return 0;
}
