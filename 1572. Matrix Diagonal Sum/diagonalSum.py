class Solution:
    def diagonalSum(self, mat: list[list[int]]) -> int:

        left = -1
        right = len(mat)
        diag_sum = 0

        for i in range(len(mat) // 2):
            left += 1
            right -= 1
            diag_sum += mat[i][left] + mat[i][right]

        i_next = len(mat) // 2

        if len(mat) % 2 == 1:
            diag_sum += mat[i_next][i_next]
            i_next += 1

        for i in range(i_next, len(mat)):
            diag_sum += mat[i][left] + mat[i][right]
            left -= 1
            right += 1

        return diag_sum