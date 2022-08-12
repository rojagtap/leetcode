import math

class Solution:
    def maxArea(self, height: List[int]) -> int:
        l = 0
        r = len(height) - 1
        water = 0
        
        while l < r:
            volume = min(height[l], height[r]) * (r - l)
            if volume > water:
                water = volume
                
            if height[l] < height[r]:
                l += 1
            else:
                r -= 1
                    
        return water