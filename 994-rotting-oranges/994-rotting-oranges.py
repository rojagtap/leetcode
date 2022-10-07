class Solution:
    # O(mn), O(mn), m is # of rows, n is # of cols, level-order bfs
    def orangesRotting(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])
        
        fresh = 0
        queue = deque()
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 2:
                    queue.append((i, j))
                elif grid[i][j] == 1:
                    fresh += 1
                
        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        
        if fresh == 0:
            return 0
        
        minutes = -1
        while queue:
            for _ in range(len(queue)):
                i, j = queue.popleft()
                
                for r, c in directions:
                    nexti, nextj = i + r, j + c
                    
                    if 0 <= nexti < rows and 0 <= nextj < cols and grid[nexti][nextj] == 1:
                        fresh -= 1
                        grid[nexti][nextj] = 2
                        queue.append((nexti, nextj))
                        
            minutes += 1
                        
        return minutes if fresh == 0 else -1
