# 16行的代码也可以直接在程序刚开始将num换成同样比特位的整数

class Solution(object):
    def toHex(self, num):
        """
        :type num: int
        :rtype: str
        """
        if num == 0:
            return '0'
        ret = []
        symbols = '0123456789abcdef'
        while num:
            index = num & 0xf
            ret.append(symbols[index])
            num = num >> 4 if num > 0 else (num % 0x100000000) >> 4

        return ''.join(s for s in ret)[::-1]

def main():
    so = Solution()
    num = 2
    print(so.toHex(num))

if __name__ == "__main__":
    main()
