// 判断一个数字是不是回文
// 小于0不是
// 12321 是

bool isPlalindrome(int num)
{
    if (num < 0)
        return false;

    int rev = 0, x = num;

    while (x != 0)
    {
        rev = rev * 10 + x % 10;
        x /= 10;
    }

    return (rev == num);
}

// 但是如果 num = 1000000003，那么 得到rev的时候会溢出

bool isPlalindrome(int num)
{
    if (num < 0)
        return false;

    int div = 1;
    // 得到 num 的最高位
    while (num / div >= 10)
        div *= 10;

    while (num != 0)
    {
        int l = num / div;
        int r = num % 10;
        // 判断数字两端的数字是否相同
        if (l != r)
            return false;

        num = (num % div) / 10;
        div /= 100;
    }

    return 0;
}

// 递归解法（如果额外的栈空间不算额外空间）。
// 通过对 x 提前除（dfs）得到 num 的第一位，和最后一位相同的话，对 y 后除来判断第二位和倒数第二位是否相同
// num 假设为 12312，执行
// x % 10 == y % 10 时，x，y 在 dfs 过程中的值如下
// 1         12321
// 12         1232
// 123         123
// 1232         12
// 12321         1

bool isPalindrome(int x, int &y)
{
    if (x < 0)
        return false;
    if (x == 0)
        return true;
    if (isPalindrome(x / 10, y) && (x % 10 == y % 10)) {
        y /= 10;
        return true;
    } else {
        return false;
    }
}

bool isPalindrome(int x)
{
    return isPalindrome(x, x);
}


// References
// https://github.com/xiangzhai/leetcode/blob/master/question/palindrome-number.md
