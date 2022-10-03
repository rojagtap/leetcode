class Solution:
    # O(mn), O(mn), bfs on disconnected graph
    def numIslands(self, grid: List[List[str]]) -> int:
        rows, cols = len(grid), len(grid[0])
        
        directions = [[-1, 0], [1, 0], [0, 1], [0, -1]]
        
        lands = [(i, j) for j in range(cols) for i in range(rows) if grid[i][j] == '1']
        visited = {lands[i]: False for i in range(len(lands))}
        
        islands = 0
        for land in lands:
            if visited[land]:
                continue
            
            islands += 1
            visited[land] = True
            queue = deque([land])
            while queue:
                i, j = queue.popleft()
                
                for x, y in directions:
                    nextx, nexty = i + x, j + y
                    if 0 <= nextx < rows and 0 <= nexty < cols and grid[nextx][nexty] == '1' and not visited[(nextx, nexty)]:
                        queue.append((nextx, nexty))
                        visited[(nextx, nexty)] = True
        
        return islands
                        
                
        