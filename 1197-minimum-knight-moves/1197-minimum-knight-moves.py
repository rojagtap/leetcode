class Solution:
#     DFS with memoization
    # O(mn), O(mn)
    def minKnightMoves(self, x: int, y: int) -> int:
        def dfs(x, y):
            if x + y == 0:
                return 0
            elif x + y == 2:
                return 2
            else:
                left_x, left_y = abs(x - 2), abs(y - 1)
                down_x, down_y = abs(x - 1), abs(y - 2)
                
                left = moves.get((left_x, left_y)) or dfs(left_x, left_y) + 1
                moves[(left_x, left_y)] = left
                
                down = moves.get((down_x, down_y)) or dfs(down_x, down_y) + 1
                moves[(down_x, down_y)] = down

                return min(left, down)
            
        moves = {(0, 0): 0}
        return dfs(abs(x), abs(y))
        

#     Bi-directional BFS
#     # O(max(x, y)2), O(max(x, y)2) squares
#     def minKnightMoves(self, x: int, y: int) -> int:
#         x, y = abs(x), abs(y)
#         directions = [[1, 2], [-1, 2], [2, 1], [2, -1], [-1, -2], [1, -2], [-2, 1], [-2, -1]]
        
#         seen_sources = {(0, 0): 0}
#         seen_dests = {(x, y): 0}
        
#         source_queue = deque([(0, 0)])
#         dest_queue = deque([(x, y)])
        
#         while True:
#             for _ in range(len(source_queue)):
#                 curr_x, curr_y = source_queue.popleft()
#                 moves = seen_sources[(curr_x, curr_y)]
#                 if (curr_x, curr_y) in seen_dests:
#                     return moves + seen_dests[(curr_x, curr_y)]
                
#                 for _x, _y in directions:
#                     next_x, next_y = (curr_x + _x, curr_y + _y)
#                     if (next_x, next_y) not in seen_sources:
#                         source_queue.append((next_x, next_y))
#                         seen_sources[(next_x, next_y)] = moves + 1
                
#             for _ in range(len(dest_queue)):
#                 curr_x, curr_y = dest_queue.popleft()
#                 moves = seen_dests[(curr_x, curr_y)]
#                 if (curr_x, curr_y) in seen_sources:
#                     return moves + seen_sources[(curr_x, curr_y)]
                
#                 for _x, _y in directions:
#                     next_x, next_y = (curr_x + _x, curr_y + _y)
#                     if (next_x, next_y) not in seen_dests:
#                         dest_queue.append((next_x, next_y))
#                         seen_dests[(next_x, next_y)] = moves + 1
    
#     BFS
#     # O(8^min(x, y)), O(8^min(x, y)) comparisons
#     # O(max(x, y)2), O(max(x, y)2) squares
#     def minKnightMoves(self, x: int, y: int) -> int:
#         x, y = abs(x), abs(y)
                
#         visited = {(0, 0)}
#         queue = deque([(0, 0, 0)])
        
#         directions = [[1, 2], [-1, 2], [2, 1], [2, -1], [-1, -2], [1, -2], [-2, 1], [-2, -1]]
#         while True:
#             curr_x, curr_y, moves = queue.popleft()
#             if curr_x == x and curr_y == y:
#                 return moves
            
#             for _x, _y in directions:
#                 next_x, next_y = (curr_x + _x, curr_y + _y)
                
#                 if (next_x, next_y) not in visited:
#                     queue.append((next_x, next_y, moves + 1))
#                     visited.add((next_x, next_y))
                    
#     Math
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
