class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        i, j = 0, len(matrix[0]) - 1
        
        while True:
            if matrix[i][j] < target:
                i += 1
                
                if i == len(matrix):
                    return False
                
            elif matrix[i][j] > target:
                j -= 1
                
                if j == -1 or matrix[i][j] < target:
                    return False
                
            else:
                return True