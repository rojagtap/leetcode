class Solution:
    """
    Do not return anything, modify matrix in-place instead.
    """
#     O(mn), O(1)
    def setZeroes(self, matrix: List[List[int]]) -> None:
        first_col = False
        
        for i in range(len(matrix)):
            if matrix[i][0] == 0:
                first_col = True
                
            for j in range(1, len(matrix[0])):
                if matrix[i][j] == 0:
                    matrix[0][j] = 0
                    matrix[i][0] = 0
            
        for i in range(1, len(matrix)):
            row_zero = matrix[i][0] == 0
            for j in range(1, len(matrix[0])):
                if row_zero or matrix[0][j] == 0:
                    matrix[i][j] = 0
                
        if matrix[0][0] == 0:
            for j in range(len(matrix[0])):
                matrix[0][j] = 0
        
        if first_col:
            for i in range(len(matrix)):
                matrix[i][0] = 0
        
    
#     O(mn), O(m + n)
#     def setZeroes(self, matrix: List[List[int]]) -> None:
        
#         rows, cols = set(), set()
        
#         i = 0
#         while i < len(matrix):
#             j = 0
#             while j < len(matrix[0]):
#                 if matrix[i][j] == 0:
#                     rows.add(i)
#                     cols.add(j)
                    
#                 j += 1
            
#             i += 1

#         zeroes = [0] * len(matrix[0])
#         for row in rows:
#             matrix[row] = zeroes
            
#         for col in cols:
#             for i in range(len(matrix)):
#                 matrix[i][col] = 0
            