class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        
        u, d = 0, len(matrix) - 1
        while u < d:
            matrix[u], matrix[d] = matrix[d], matrix[u]
            u += 1
            d -= 1
        
        for i in range(len(matrix)):
            for j in range(i):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
        
        return matrix