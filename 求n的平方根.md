# 计算n的平方根

## [无名](https://stackoverflow.com/a/14371766/6074780)

求$x$使得$x^2=n$，即求$x$使得$x=\frac{n}{x}$。

1. 猜测一个值$x$，然后测试$x^2$是不是足够接近$n$。
2. 如果足够接近，返回$x$。否则，进行更好的猜测。

```
def sqrt(n, x):
    if close_enough(x, n / x):
        return x
    else:
        return sqrt(n, better_guess(n, x))

def close_enough(a, b):
    return abs(a - b) < 1e-5

def better_guess(n, x):
    return (x + n / x) / 2
```

需要注意的是，这种方法求很小的值的平方根由于`close_enough`函数的原因会出错：

```
[ins] In [5]: sqrt(1E-36, 1)                                                                                              
Out[5]: 7.62939453125e-06

[ins] In [6]: math.sqrt(1E-36)                                                                                            
Out[6]: 9.999999999999999e-19
```

错误就是传入`close_enough`的参数均远小于我们评价的阈值。

改进的`close_enough`:

```
def close_enough(a, b):
    return (abs(a - b) / (max(abs(a), abs(b)))) < 1e-5
```

## 二分法

```
def sqrt(n):
    left, right = 0, n
    while True:
        mid = (left + right) / 2
        res = mid**2 - n
        if abs(res) < 1e-5:
            return mid
        elif res > 0:
            right = mid
        else:
            left = mid
```

同样这里的评价条件，需要改进。

## 牛顿法

这里就是求函数$f(x)=x^2-n$的零点。

$x_{n+1} = x_n - \frac{f(x)}{f\prime (x)}$

```
def sqrt(n):
    x = n
    while abs(x**2 - n) > 1e-5:
        x = (x + n / x) / 2
    return x
```

同样这里的评价条件，需要改进。
