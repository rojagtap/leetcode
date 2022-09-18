class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        i, j = 0, len(matrix[0]) - 1
        
        pointer = matrix[i][j]
        while True:
            if pointer < target:
                i += 1
                if i == len(matrix):
                    return False
                
                pointer = matrix[i][-1]
            elif pointer > target:
                j -= 1
                
                if j == -1 or matrix[i][j] < target:
                    return False
                
                pointer = matrix[i][j]
            else:
                return True