// 求一个字符串中的最长回文字符序列的长度

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
        
    // i 表示 当前长度为 i+1的 子序列
    for(int i=1; i<n; i++)
    {
        tmp = 0;
        //考虑所有连续的长度为i+1的子串. 该串为 str[j, j+i]
        for(int j=0; j+i<n; j++)
        {
            //如果首尾相同
            if(s[j] == s[j+i])
            {
                tmp = dp[j+1][j+i-1] + 2;
            }
            else
                tmp = max(dp[j+1][j+i],dp[j][j+i-1]);

            dp[j][j+i] = tmp;
        }
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
