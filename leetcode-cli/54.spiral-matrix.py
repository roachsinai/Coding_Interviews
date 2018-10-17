class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        if not matrix:
            return []
        rows = len(matrix)
        cols = len(matrix[0])
        ret = matrix[0]
        move_vector = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        i, j = 0, cols-1
        index = 1
        # available_steps代表在当前的移动方向还可以移动几步
        col_available_steps = cols- 1
        row_available_steps = rows - 1
        num_elems = (rows - 1) * cols
        while num_elems > 0:
            for step in range(row_available_steps):
                num_elems -= 1
                i += move_vector[index][0]
                j += move_vector[index][1]
                ret.append(matrix[i][j])
            row_available_steps -= 1
            row_available_steps, col_available_steps = \
                    col_available_steps, row_available_steps
            index = (index + 1) % 4
        return ret
