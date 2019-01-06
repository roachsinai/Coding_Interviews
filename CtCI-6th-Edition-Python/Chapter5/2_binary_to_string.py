# 返回一个浮点小数的二进制表示，如果32个二进制位无法表示该小数的精度，raise ERROR
#
# 解法一，得到小数的浮点表示：1个符号位，11个指数位，52个小数位的后20位如果非0，表示超出精度
# IEEE754标准中小数的整数部分都是1*符号位（但是二进制表示时去掉了1，转换为小数时再添上），所
# 以使用上述方法的输入为小数加上1
#
# 解法二，小数乘以2，如果大于1，说明对应浮点表示的小数部分第一位为1。将乘以2之后的数减去1之后
# 的小数部分即原来小数部分的第二位
#
# 解法三，小数如果大于0.5，说明浮点表示的小数部分的第一位是1。减去0.5之后如果大于0.25说明浮点
# 表示的第二位为1，然后减去0.25，否则第二位为0，不用减0.25.

import ctypes


def binary_to_string(number):
    if number == 1:
        return "1.0"
    if number == 0:
        return "0.0"
    if number < 0 or number > 1:
        return Exception("Out of bounds")
    normalized = bits_for(number + 1.0)
    bits = normalized & ((1 << 52) - 1)
    if normalized & ((1 << 20) - 1):
        return Exception("Insufficient precision")

    digits = ["0."]
    bit = (1 << 51)
    while bits:
        if bits & bit:
            digits.append("1")
        else:
            digits.append("0")
        bits &= ~bit
        bit >>= 1
    return "".join(digits)


def bits_for(number):
    return ctypes.c_longlong.from_buffer(ctypes.c_double(number)).value


def binary_to_string1(number):
    if number == 1:
        return "1.0"
    if number == 0:
        return "0.0"
    if number < 0 or number > 1:
        return Exception("Out of bounds")
    digits = ["0."]
    while number > 0:
        if len(digits) > 32:
            return Exception("Insufficient precision")
        number *= 2
        if number >= 1:
            digits.append("1")
            number -= 1
        else:
            digits.append("0")
    return "".join(digits)


def binary_to_string2(number):
    if number == 1:
        return "1.0"
    if number == 0:
        return "0.0"
    if number < 0 or number > 1:
        return Exception("Out of bounds")
    digits = ["0."]
    frac = .5
    while number > 0:
        if len(digits) > 32:
            return Exception("Insufficient precision")
        if number >= frac:
            digits.append("1")
            number -= frac
        else:
            digits.append("0")

        frac /= 2
    return "".join(digits)

import unittest


class Test(unittest.TestCase):

    def test_binary_to_string(self):
        self.assertEqual(binary_to_string(0.75), "0.11")
        self.assertEqual(binary_to_string(0.625), "0.101")
        self.assertEqual(str(binary_to_string(0.3)), "Insufficient precision")
        self.assertEqual(binary_to_string1(0.75), "0.11")
        self.assertEqual(binary_to_string1(0.625), "0.101")
        self.assertEqual(str(binary_to_string1(0.3)), "Insufficient precision")
        self.assertEqual(binary_to_string2(0.75), "0.11")
        self.assertEqual(binary_to_string2(0.625), "0.101")
        self.assertEqual(str(binary_to_string2(0.3)), "Insufficient precision")


if __name__ == "__main__":
    unittest.main()
