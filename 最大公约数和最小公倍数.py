## 辗转相除法

# 计算 gcd(18,48) 时，先将 48 除以 18 得到商 2、余数 12，然后再将 18 除以 12 得到商 1、余数 6，再将 12 除以 6 得到商 2、余数 0，即得到最大公因数 6 。我们只关心每次除法的余数是否为 0，为 0 即表示得到答案。
# 原理：如果
# rem = x%y
# 如果 div 是 y 和 x%y 的最大公约数
# 那 div 一定也是 x 的公约数，因为 x = x % y + m * y
# div 能被 x%y 和 y 整除，x 就一定可以

def gcd(x, y):
    if y == 0:
        return x
    if x < y:
        x, y = y, x
    return gcd(y, x%y)

t1 = 10
t2 = 15

lcm = t1 * t2 / gcd(t1, t2)

print("least common multiple of {} and {} is\n {}".format(t1, t2, lcm))


# pythonic 但是结果不对，不满足 x > y

def gcd(x, y):
    while y:
        x, y = y, x%y
    return x
