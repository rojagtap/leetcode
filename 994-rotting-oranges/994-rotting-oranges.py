class Solution:
    # O(mn), O(mn), level-order bfs
    def orangesRotting(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])
        
        rotten = empty = 0
        queue = deque()
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 2:
                    queue.append((i, j))
                    rotten += 1
                elif grid[i][j] == 0:
                    empty += 1
                
        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        
        if rotten == (rows * cols) - empty:
            return 0
        
        minutes = -1
        while queue:
            for _ in range(len(queue)):
                i, j = queue.popleft()
                
                for r, c in directions:
                    nexti, nextj = i + r, j + c
                    
                    if 0 <= nexti < rows and 0 <= nextj < cols and grid[nexti][nextj] == 1:
                        rotten += 1
                        grid[nexti][nextj] = 2
                        queue.append((nexti, nextj))
                        
            minutes += 1
                        
        return minutes if rotten == (rows * cols) - empty else -1
