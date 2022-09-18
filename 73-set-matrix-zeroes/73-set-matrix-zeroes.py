class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        
        rows, cols = set(), set()
        
        i = 0
        while i < len(matrix):
            j = 0
            while j < len(matrix[0]):
                if matrix[i][j] == 0:
                    rows.add(i)
                    cols.add(j)
                    
                j += 1
            
            i += 1

        zeroes = [0] * len(matrix[0])
        for row in rows:
            matrix[row] = zeroes
            
        for col in cols:
            for i in range(len(matrix)):
                matrix[i][col] = 0
            