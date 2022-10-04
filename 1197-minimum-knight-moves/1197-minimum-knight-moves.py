class Solution:
    # O(1), O(1)
    def minKnightMoves(self, x: int, y: int) -> int:
        x, y = abs(x), abs(y)
        if x < y:
            x, y = y, x
        
        if x == 1 and y == 0:
            return 3        
        elif x == 2 and y == 2:
            return 4   
        
        delta = x - y
        if y > delta:
            return delta - 2 * math.floor((delta - y) // 3)
        else:
            return delta - 2 * math.floor((delta - y) // 4)
