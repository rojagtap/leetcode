class Solution:
    # O(mn), O(mn), level-order bfs
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        
        area = 0
        for i in range(rows):
            for j in range(cols):
                if grid[i][j]:
                    grid[i][j] = 0
                    queue = deque([(i, j)])
                    
                    land = 0
                    while queue:
                        for _ in range(len(queue)):
                            land += 1
                            
                            r, c = queue.popleft()
                            for x, y in directions:
                                nextr, nextc = r + x, c + y
                                if 0 <= nextr < rows and 0 <= nextc < cols and grid[nextr][nextc]:
                                    grid[nextr][nextc] = 0
                                    queue.append((nextr, nextc))
                                    
                    area = max(area, land)
                    
        return area