假如 `m` 和 `n` 属于 `1 ~ 1E8` 且 `n > m`，那么求它们之间质数的个数。

对于这种题，我们可以先求出小于 `n` 的质数表。方法如下：

1. 开辟存放 `n` 个元素的数组，并全置 0 表示都为质数
2. 遍历数组将值为当前元素倍数的位置都置 1 表示为 合数
3. 遍历的同时将判断为质数的复制到数组前端，这样遍历结束数组前端极为小于 `n` 的质数表

然后可以使用，二分查找，来最终确定目标质数的起始和结束位置（第一个目标质数的平方大于等于 `m`，最后一个质数的平方小于等于 `n` ）。

```
class PrimeNumber
{
public:
    PrimeNumber(int m, int n)
    {
        int PRIMES[n];
        memeset(PRIMES, 0, sizeof(PRIMES));
        int j = 0;
        for(int i = 2; i < MAX_NUM; ++ i)
            if (!PRIMES[i])
            {
                PRIMES[j ++] = i;
                for (int k = 2*i; k < MAX_NUM; k += i)
                    PRIMES[k] = 1;  // k对应的数字不是质数
            }
    }
}
```

上面的代码就得到了`2 ~ MAX_NUM`之间所有的质数，`j`表示质数的个数，`0`和`j-1`是这些质数第一个和最后一个元素的下标。
