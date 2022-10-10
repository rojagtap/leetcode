class Solution:
    # O(mn), O(mn)
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        
        maxarea = 0
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 1:
                    grid[i][j] = -1
                    queue = deque([(i, j)])
                    
                    area = 0
                    while queue:
                        for _ in range(len(queue)):
                            area += 1
                            
                            r, c = queue.popleft()
                            for x, y in directions:
                                nextr, nextc = r + x, c + y
                                if 0 <= nextr < rows and 0 <= nextc < cols and grid[nextr][nextc] == 1:
                                    grid[nextr][nextc] = -1
                                    queue.append((nextr, nextc))
                                    
                    maxarea = max(maxarea, area)
                    
        return maxarea