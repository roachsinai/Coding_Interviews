## 字符串匹配算法

对于一个字符串：bread 其前缀为：b, br, bre, brea; 后缀为: read, ead, ad, d;在这个例子中，字符串的前后缀中没有共有元素。而`KMP`算法用到了`最长共有元素的长度`。

那么一个待匹配字符串：ABCDABD，它的前缀字串包括：A,AB,ABC,ABCD,ABCDA,ABCDAB,以及它自身ABCDABD.这7个字串各自的最长共有元素长度分别为：

|搜索词|A|B|C|D|A|B|D|
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|部分搜索词|0|0|0|0|1|2|0|

上面的每个字母是7个字串的最后一个字母，而这个其实就是算法中的`next`数组，又叫`部分匹配表`。数字就是每个字串各自的最长共有元素的长度（各自前缀和后缀中共有的）。详细步骤：

- "A"的前缀和后缀都为空集，共有元素的长度为0；
- "AB"的前缀为[A]，后缀为[B]，共有元素的长度为0；
- "ABC"的前缀为[A, AB]，后缀为[BC, C]，共有元素的长度0；
- "ABCD"的前缀为[A, AB, ABC]，后缀为[BCD, CD, D]，共有元素的长度为0；
- "ABCDA"的前缀为[A, AB, ABC, ABCD]，后缀为[BCDA, CDA, DA, A]，共有元素为"A"，长度为1；
- "ABCDAB"的前缀为[A, AB, ABC, ABCD, ABCDA]，后缀为[BCDAB, CDAB,DAB, AB, B]，共有元素为"AB"，长度为2；
- "ABCDABD"的前缀为[A, AB, ABC, ABCD, ABCDA, ABCDAB]，后缀为[BCDABD, CDABD, DABD, ABD, BD, D]，共有元素的长度为0。

#### next数组的作用

那么`next`数组有什么作用呢？

那下面的例子来说明一下：有一个字符串"BBC ABCDAB ABCDABCDABDE"，那么它里面是否包含另一个字符串"ABCDABD"？

暴力法，从源字符串的第一个字符开始共7个字符和目标字符串匹配，不成功则后移一位，时间复杂度O(n*m);但是，其实一次匹配不成功，后移几位再次进行匹配是可以优化的。比如：

![](/img/kmp1.png)

我们发现匹配到这里`D`没有匹配成功，那我们是要将待匹配字符串后移一个位置从新匹配么？显然不是，这样太慢了。那我们应该怎么办？可以发现已经匹配上的字符串`ABCDAB`的最长公共元素长度为`AB`，也就是**说我们知道了下一个最近的`AB`字串出现的位置**，我们需要从当前位置后移`6-2`个位置，再直接看第6个位置是否匹配。其中6是当前已经匹配上的字串的长度，2是已经匹配上的字串的最长公共元素的长度，即`next`数组上的值。

![](/img/kmp2.png)

#### 求next数组

那么，编程如何求`next`数组，即每个字串的最长公共元素长度呢？不，如何快速的求`next`数组呢？就是在求`next`数组的过程中，用到前面已经求得的`next`数组的信息。

假设，当前已经求得的最长公共与元素长度为`k`的字串为`P[0]...p[q-1]`，其最长公共元素为：`P[0]...P[k-1]`，如图一所示：

![](/img/kmp3.png)

那么，在下一个位置(图中红色`比较`两字所处的位置)，如果`P[q]==P(k)`，那很好字符串`P[0]...P[q]`最长公共元素长度为`k+1`。但是，如果不相等呢？是字符串`P[0]...P[q]`的最长公共长度为`0`么？不一定。

我们现在其实要求的就是'P[0]...P[q]'的后缀和前缀最长相同字串的长度。而已经知道字符串`P[0]...P[q-1]`的前`k`个元素和后`k`个与元素相同，但是`P[q] != P[k]`。那我们就要找到`P[0]...P[q-1]`前缀中的最长公共元素`P[0]...P[j-1]`（这一步可以通过`next`数组确定），然后比较其下一个元素是否与`P[q]`相等。如下图所示：

![](/img/kmp4.png)

当然，`P[0]...P[k-1]`可能没有相同的前后缀那就是比较`P[q]`和`P[0]`是否一样。

`code:`

```
void get_next(const char P[], int next[])
{
    int q; // 待匹配字符串的下标
    int k; // 最大相同前后缀长度，初始化为0
    int m = strlen(P); // 待匹配字符串的长度

    next[0] = 0; // 单字符的前后缀均为空，所以长度为0
    for (q = 1, k = 0; q < m; ++ q)
    {
        while (k > 0 && P[q] != P[k]) // 图二步骤
            k = next[k-1];
        if (P[q] == P[k])
            ++ k;

        next[q] = k;
    }
}
```

`completed code:`

```
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void get_next(const string& sub_str, int next[])
{
    int q; // 待匹配字符串下标
    int k; // 前后缀最长公共元素长度
    next[0] = 0;

    for (q = 1, k = 0; q < sub_str.size(); ++ q)
    {
        while (k > 0 && sub_str[q] != sub_str[k])
            k = next[k-1];

        if (sub_str[q] == sub_str[k])
            ++ k;

        next[q] = k;
    }
}

void KMP(const string& str, const string& sub_str, int next[])
{

    for (int i = 0, j = 0; i < str.size(); ++ i)
    {
        while (j > 0 && str[i] != sub_str[j])
            j = next[j-1];

        if (str[i] == sub_str[j])
            ++ j;

        if (j == sub_str.size())
            cout << "pattern begin from index " << i-j+1 << endl;
        }
}

int main(){
    string str("ababxbababcadfdsss");
    string sub_str("abcadfd");

    int* next = new int[sub_str.size()];
    memset(next, 0, sizeof(next));
    get_next(sub_str, next);

    KMP(str, sub_str, next);

    return 0;
}
```


#### References

1. [【经典算法】——KMP，深入讲解next数组的求解](http://www.cnblogs.com/c-cloud/p/3224788.html)
