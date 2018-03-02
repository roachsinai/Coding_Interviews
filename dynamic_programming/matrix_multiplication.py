# dp[i][j] 表示第i个矩阵与第j个矩阵所有矩阵相称所需的最少乘法次数
def matrix_chain_order(arr):
    num_matrix = len(arr) - 1;

    dp = [[0]*num_matrix for _ in range(num_matrix)]

    for n in range(2, len(arr)):
        for i in range(0, num_matrix+1-n):
            j = i + n -1
            dp[i][j] = float('inf')
            for k in range(i, j):
                min = dp[i][k] + dp[k+1][j] + arr[i] * arr[k+1] * arr[j+1]
                dp[i][j] = min if min < dp[i][j] else dp[i][j]

    return dp[0][num_matrix - 1], dp

def main():
    arr = [1, 2, 3, 4]
    min_mul, dp = matrix_chain_order(arr)
    print("Minimum number of multiplication is {}".format(min_mul))
    print(dp)

if __name__ == "__main__":
    main()
