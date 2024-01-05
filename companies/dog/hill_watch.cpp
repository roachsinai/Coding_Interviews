// [E. Bindian Signalizing](http://codeforces.com/contest/5/problem/E)

// 多个烽火台围成一圈，两个烽火台可以看见，当且仅当，它们之间没有高于任一方的烽火台，求可以看见的烽火台的对数？
// 统计对数，为了不重复统计。这里只统计低的烽火台看见高的烽火台这样的对数
// 这就需要统计对于一个烽火台i，它左边第一个高于它的烽火台位置；它右边高于它的烽火台的位置；以及，这之间和它高度相同的烽火台的位置。
// 之所以统计这些是：
//      拦截效果，出现一个高于它的烽火台，之后的就看不到了；
//      高度相同的可以互相看见；
//      只需要统计比自己高的（比自己低的数目有低的来统计）；
//      高度相同的,统计在区间内后面和自己相同高度的个数加上即可；比如共有5个，当前加4个

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n, x;
    cin >> n;
    vector<int> height(n);
    for (int i = 0; i < n; ++ i)
    {
        cin >> x;
        height[i] = x;
    }
    vector<int>::iterator highest = max_element(height.begin(), height.end());

    // 旋转数组，使得高度最高的烽火台，放在第一个位置
    vector<int> num(highest, height.end());
    num.reserve(n);
    copy(height.begin(), highest, num.end());

    // left 中存放的是 num[i] 左边 nearest bigger number 的索引
    vector<int> left(n, -1);
    for (int i = 1; i < n; ++ i)
    {
        int p = i-1;
        while (num[i] > num[p])  // 因为最大的元素在左端， p 不会越界
            p = left[p];
        left[i] = num[i] == num[p] ? left[p] : p;
    }

    // right[i] is the nearest bigger number in the right of num[i]
    // same[i] is the number of the number equal to num[i] in [i, right[i]]
    vector<int> right(n, n);
    vector<int> same(n, 0);
    for (int i = n-2; i >= 0; -- i)
    {
        int p = i + 1;
        while (p < n && num[i] > num[p])
            p = right[p];

        if (p >= n)
        {
            right[i] = p;
            continue;
        }

        right[i] = num[i] == num[p] ? right[p] : p;
        same[i] = num[i] == num[p] ? same[i] + 1 : 0;
    }

    long long ans = 0;
    for (int i = 0; i < n; ++ i) {
        if (left[i] >= 0)
            ans += 1;
        if (right[i] < n)
            ans += 1;
        if (right[i] >= n && left[i] > 0)
            ans += 1;  // 最后一个元素肯定可以看见第一个元素
        ans += same[i];
    }

    cout << ans << endl;

    return 0;
}
