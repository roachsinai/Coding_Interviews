# 判断一个数字是不是回文
# 小于0不是
# 12321 是

def is_plalindrome(num):
    if num < 0:
        return False
    
    rev, x = 0, num
    while x != 0:
        rev = rev * 10 + x % 10
        x //= 10
    
    return rev == num

def main():
    print(is_plalindrome(12321))

if __name__ == "__main__":
    main()