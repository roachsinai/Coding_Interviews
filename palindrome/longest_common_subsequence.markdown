题目：求两个字符串中最长的公共子串的字符个数
测试："abcddacdac" "abdac" 输出：3

思路：动态规划

|0|...|i-1|i|...|m|
|:---|:---|:---|:---|:---|:---|
|0|...|j-1|j|...|m|

假如现在求第一个字符串`i`之前和第二个字符串`j`之前的最长公共字串`a[i][j]`，而`a[i-1][j-1]`已经求出。

那么如果`s1[i] == s2[j]`，则`a[i][j] = a[i][j] + 1`否则`a[i][j] = max(a[i][j-1], a[i-1][j])`.

这里的意思是：如果`i`和`j`处字符相同，那么最长子序列长度就加一，否则这里最长子序列的长度就是前缀序列`i`和`j-1`或者`i-1`和`j`两者之间最长子序列长度的大者。

事实上，之所以`否则，a[i][j] = 0`，是因为这样不影响数组中存在最长公共子串的字符个数。

code:

```
string s1, s2;
int m = s1.size();
int n = s2.size();
int max(int a, int b);

int a** = new int*[m+1];
a[i] = new int[n+1];

// 第一列初始化为0
for (int i = 0; i < m+1; ++ i)
    a[i][0] = 0;

// 第一行初始化为0
for (int j = 0; j < n+1; ++ j)
    a[0][j] = 0;

for (int i = 1; i < m+1; ++ i)
    for (int j = 1; j < n+1; ++ j)
        if (s1[i-1] == s2[j-1])
            a[i][j] = a[i-1][j-1] + 1;
        else
            a[i][j] = max(a[i][j-1], a[i-1][j]);

return a[m][n];

int max(int a, int b)
{
    return (a > b ? a : b);
}
```
