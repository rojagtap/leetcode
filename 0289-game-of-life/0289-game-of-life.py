class Solution:
    '''
    For follow up 2, scaling, one can read one line at a time and after 2 lines perform the same logic
    '''
    
    # O(mn), O(1)
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        
        # 2 if prev 0 now 1
        # 3 if prev 1 now 0
        
        rows = len(board)
        cols = len(board[0])
        
        for i in range(rows):
            for j in range(cols):
                neighbors = 0
                for r in range(i - 1, i + 2):
                    for c in range(j - 1, j + 2):
                        neighbors += 1 if 0 <= r < rows and 0 <= c < cols and (r, c) != (i, j) and (board[r][c] == 1 or board[r][c] == 3) else 0
                
                if board[i][j] == 1:
                    board[i][j] = board[i][j] if 2 <= neighbors <= 3 else 3
                elif board[i][j] == 0:
                    board[i][j] = 2 if neighbors == 3 else board[i][j]
                    
        for i in range(rows):
            for j in range(cols):
                board[i][j] = 1 if board[i][j] == 2 else 0 if board[i][j] == 3 else board[i][j]
        