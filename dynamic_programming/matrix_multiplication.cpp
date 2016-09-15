// arr 存放 每个矩阵的维度 第 i 个矩阵的维度为 arr[i-1] * a[i]，那么给定 arr 的大小: size，则举着个数有 size-1 个
// M[i][j] 表示 A[i]A[i+1]...A[j] 的连乘最小代价
// 那么，最终要求的是 A[1]A[2]...A[n-1] 即 M[1][n-1]

#include <iostream>
#include <climits>

using namespace std;

int MatrixChainOrder(int p[], int n)
{
    int M[n][n];
    int i, j, k, L, min;

    for (i = 1; i < n; ++ i)
        M[i][i] = 0;

    // L is length
    for (L = 2; L < n; ++ L)
        for (i = 1; i+L-1 < n; ++ i)
        {
            j = i+L-1;
            M[i][j] = INT_MAX;

            for (k = i; k+1 <= j; ++ k)
            {
                min = M[i][k] + M[k+1][j] + p[i-1]*p[k]*p[j];
                if (min < M[i][j])
                    M[i][j] = min;
            }
        }

    return M[1][n-1];
}

int main()
{
    int arr[] = {1, 2, 3, 4};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << MatrixChainOrder(arr, size) << endl;

    return 0;
}
