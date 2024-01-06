def lcs(str1, str2):
    len1, len2 = len(str1)+1, len(str2)+1

    # len1xlen2
    v = [[0]*len2 for _ in range(len1)]

    for i in range(1, len1):
        for j in range(1, len2):
            if str1[i-1] == str2[j-1]:
                v[i][j] = v[i-1][j-1] + 1
            else:
                v[i][j] = max(v[i-1][j], v[i][j-1])

    return v[len(str1)][len(str2)]

def main():
    str1 = "abcddacdac"
    str2 = "abdac"

    print(lcs(str1, str2))

if __name__ == "__main__":
    main()
