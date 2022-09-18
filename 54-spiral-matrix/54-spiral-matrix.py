class Solution:
#     O(rc), O(1)
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        traversal = []
        rows, cols = len(matrix), len(matrix[0])
        rowsxcols = rows * cols
        
        # boundaries in order right, bottom, left, top
        right, bottom, left, top = cols, rows, -1, -1
        
        i = j = 0
        traversal.append(matrix[i][j])
        while len(traversal) < rowsxcols:
            while j < right - 1:
                j += 1
                traversal.append(matrix[i][j])
            
            if len(traversal) == rowsxcols:
                break
                
            top += 1
            
            while i < bottom - 1:
                i += 1
                traversal.append(matrix[i][j])
            
            if len(traversal) == rowsxcols:
                break
                
            right -= 1
            
            while j > left + 1:
                j -= 1
                traversal.append(matrix[i][j])
            
            if len(traversal) == rowsxcols:
                break
                
            bottom -= 1
                
            while i > top + 1:
                i -= 1
                traversal.append(matrix[i][j])
            
            if len(traversal) == rowsxcols:
                break
                
            left += 1
        
        return traversal
