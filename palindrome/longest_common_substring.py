def lcs(str1, str2):
    len1, len2 = len(str1)+1, len(str2)+1

    v = [[0]*len2 for _ in range(len1)]

    max_substring_len = 0
    for i in range(1, len1):
        for j in range(1, len2):
            if str1[i-1] == str2[j-1]:
                v[i][j] = v[i-1][j-1] + 1
                max_substring_len = max_substring_len \
                                        if max_substring_len > v[i][j] \
                                        else v[i][j]
            else:
                v[i][j] = 0

    return max_substring_len

def main():
    str1 = "abcddacdac"
    str2 = "abdac"

    print(lcs(str1, str2))

if __name__ == "__main__":
    main()