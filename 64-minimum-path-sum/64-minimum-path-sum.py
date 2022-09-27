import math

class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])
        prefixsum = [[0 for j in range(cols + 1)] for i in range(rows + 1)]
        
        for i in range(1, rows + 1):
            prefixsum[i][1] = prefixsum[i - 1][1] + grid[i - 1][0]
                
        for j in range(1, cols + 1):
            prefixsum[1][j] = prefixsum[1][j - 1] + grid[0][j - 1]
            
        for i in range(2, rows + 1):
            for j in range(2, cols + 1):
                prefixsum[i][j] = grid[i - 1][j - 1] + min(prefixsum[i - 1][j], prefixsum[i][j - 1])
        
        return prefixsum[rows][cols]
    
#     # O(2n), O(n), dfs
#     def minPathSum(self, grid: List[List[int]]) -> int:
#         def get_min(i, j, currsum):
#             currsum += grid[i][j]
#             if i == len(grid) - 1 and j == len(grid[i]) - 1:
#                 return currsum                
            
#             rightsum = get_min(i, j + 1, currsum) if j + 1 < len(grid[i]) else math.inf
#             leftsum = get_min(i + 1, j, currsum) if i + 1 < len(grid) else math.inf
            
#             return min(rightsum, leftsum)
        
#         return get_min(0, 0, 0)