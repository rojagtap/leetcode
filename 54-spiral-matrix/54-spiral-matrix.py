class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        traversal = []
        
        # boundaries in order right, bottom, left, top
        right, bottom, left, top = len(matrix[0]), len(matrix), -1, -1
        
        i = j = 0
        traversal.append(matrix[i][j])
        while len(traversal) < len(matrix) * len(matrix[0]):
            while j < right - 1:
                j += 1
                traversal.append(matrix[i][j])
            
            if len(traversal) == len(matrix) * len(matrix[0]):
                break
                
            top += 1
            
            while i < bottom - 1:
                i += 1
                traversal.append(matrix[i][j])
            
            if len(traversal) == len(matrix) * len(matrix[0]):
                break
                
            right -= 1
            
            while j > left + 1:
                j -= 1
                traversal.append(matrix[i][j])
            
            if len(traversal) == len(matrix) * len(matrix[0]):
                break
                
            bottom -= 1
                
            while i > top + 1:
                i -= 1
                traversal.append(matrix[i][j])
            
            if len(traversal) == len(matrix) * len(matrix[0]):
                break
                
            left += 1
        
        return traversal
                
                
        
        