import math

class Solution:
    # O(mn), O(1)
    def minPathSum(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])
        
        for i in range(1, rows):
            grid[i][0] += grid[i - 1][0]
                
        for j in range(1, cols):
            grid[0][j] += grid[0][j - 1]
            
        for i in range(1, rows):
            for j in range(1, cols):
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1])
        
        return grid[rows - 1][cols - 1]
    
#     # O(2^(m + n)), O(m + n), dfs
#     def minPathSum(self, grid: List[List[int]]) -> int:
#         def get_min(i, j, currsum):
#             currsum += grid[i][j]
#             if i == len(grid) - 1 and j == len(grid[i]) - 1:
#                 return currsum                
            
#             rightsum = get_min(i, j + 1, currsum) if j + 1 < len(grid[i]) else math.inf
#             leftsum = get_min(i + 1, j, currsum) if i + 1 < len(grid) else math.inf
            
#             return min(rightsum, leftsum)
        
#         return get_min(0, 0, 0)