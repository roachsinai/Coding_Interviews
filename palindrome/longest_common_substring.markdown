题目：求两个字符串中最长的公共子串的字符个数
测试："abcddacdac" "abdac" 输出：3

思路：动态规划

|0|...|i-1|i|...|m|
|:---|:---|:---|:---|:---|:---|
|0|...|j-1|j|...|m|

假如现在求第一个字符串`i`之前和第二个字符串`j`之前的最长公共字串`a[i][j]`，而`a[i-1][j-1]`已经求出。

那么如果`s1[i] == s2[j]`，则`a[i][j] = a[i][j] + 1`否则`a[i][j] = 0`.

这里的意思是：只有连续相等，才能称为最大子串。

事实上，上面说的`否则，a[i][j] = 0`，是因为下面的代码起始时只初始化了 dp 数组中的部分区域（一行和一列）。

code:

```
string s1, s2;
int m = s1.size();
int n = s2.size();
int max_len = 0;

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
        {
            a[i][j] = a[i-1][j-1] + 1;
            if (a[i][j] > max_len)
                max_len = a[i][j];
        }
        else
            a[i][j] = 0;

return max_len;
```
