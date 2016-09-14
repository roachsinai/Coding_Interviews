// 求一个字符串中的最长回文子序列的长度
// if (s[i] == s[j]) dp[i][j] = dp[i+1][j-1] + 2;
// if (s[i] != s[j]) dp[i][j] = max(dp[i+1, j], dp[i][j-1])

#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int max(int a, int b)
{
    return (a > b ? a : b);
}

int longestPalindromeSubSequence(string s)
{
    const int n = s.size();
    int dp[n][n], tmp;
    memset(dp,0,sizeof(dp));
    for(int i=0; i<n; i++)
        dp[i][i] = 1;

    // len 子序列的长度
    for(int len = 2; len <= n; ++ len)
        for(int i = 0; i+len < n; ++ i)
        {
            if (s[i] == s[i+len-1])
                dp[i][i+len-1] = dp[i+1][i+len-2] + 2;
            else
                dp[i][i+len-1] = max(dp[i+1][i+len-1], dp[i][i+len-2]);
        }

    //返回串 str[0][n-1] 的结果
    return dp[0][n-1];
}
int main()
{
    string str;
    cin >> str;
    cout << longestPalindromeSubSequence(str) << endl;

    return 0;
}
