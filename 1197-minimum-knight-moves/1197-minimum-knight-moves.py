class Solution:
    # O(8^min(x, y)), O(1)
    def minKnightMoves(self, x: int, y: int) -> int:
        x, y = abs(x), abs(y)
        directions = [[1, 2], [-1, 2], [2, 1], [2, -1], [-1, -2], [1, -2], [-2, 1], [-2, -1]]
        
        visited = set([(0, 0)])        
        queue = deque([(0, 0, 0)])
        while queue:
            curr_x, curr_y, moves = queue.popleft()
            if curr_x == x and curr_y == y:
                return moves
            
            for _x, _y in directions:
                next_x, next_y = (curr_x + _x, curr_y + _y)
                if (next_x, next_y) not in visited:
                    queue.append((next_x, next_y, moves + 1))
                    visited.add((next_x, next_y))
                    
                    
#     # O(1), O(1)
#     def minKnightMoves(self, x: int, y: int) -> int:
#         x, y = abs(x), abs(y)
#         if x < y:
#             x, y = y, x
        
#         if x == 1 and y == 0:
#             return 3        
#         elif x == 2 and y == 2:
#             return 4   
        
#         delta = x - y
#         if y > delta:
#             return delta - 2 * math.floor((delta - y) // 3)
#         else:
#             return delta - 2 * math.floor((delta - y) // 4)
