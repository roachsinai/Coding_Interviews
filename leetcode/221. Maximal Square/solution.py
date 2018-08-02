class Solution:
    def maximalSquare(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        if not matrix:
            return 0

        ROWS = len(matrix)
        COLS = len(matrix[0])

        dp = [[0]*COLS for _ in range(ROWS)]
        max_size = 0

        for i in range(0, COLS):
            dp[0][i] = int(matrix[0][i])
            max_size = max_size if max_size > dp[0][i] else dp[0][i]

        for i in range(0, ROWS):
            dp[i][0] = int(matrix[i][0])
            max_size = max_size if max_size > dp[i][0] else dp[i][0]

        for i in range(1, ROWS):
            for j in range(1, COLS):
                if matrix[i][j] == '0':
                    dp[i][j] = 0
                else:
                    dp[i][j] = min(dp[i-1][j-1], dp[i][j-1], dp[i-1][j]) + 1
                max_size = max_size if max_size > dp[i][j] else dp[i][j]
        
        return max_size**2