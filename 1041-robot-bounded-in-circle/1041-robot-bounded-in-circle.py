class Solution:
    def isRobotBounded(self, instructions: str) -> bool:
        g = {
            0: (0, 1),
            1: (1, 0),
            2: (0, -1),
            3: (-1, 0)
        }
        
        direction = 1
        x, y = 0, 0
        for instruction in instructions:
            if instruction == "G":
                x += g[direction][0]
                y += g[direction][1]
            elif instruction == "L":
                direction = (direction - 1) % 4
            elif instruction == "R":
                direction = (direction + 1) % 4
                
        if direction != 1 or x == 0 and y == 0:
            return True
        else:
            return False