class Solution:
    '''
    Calculate for one index at a time
    
    for any given index, the maximum water it can trap is the min of maximum elevation to the left and maximum elevation to the right - itself. For example:
    
    lmax        rmax
      ↓           ↓
                 __
     __         |  |
    |  |__    __|  |
    |  |  |  |  |  |
         ↑
      current
      
    so the amount of water that current can trap is min(lmax, rmax) - height[current]
    
    '''
    
#     O(n), O(1), two pointers
    def trap(self, height: List[int]) -> int:
        lmax = rmax = 0
        l, r = 0, len(height) - 1
        
        water = 0
        while l < r:
            if height[l] < height[r]:
                lmax = max(lmax, height[l])
                water += (lmax - height[l])
                l += 1
            else:
                rmax = max(rmax, height[r])
                water += (rmax - height[r])
                r -= 1
        
        return water
        
        
#     O(n), O(n), arrays for lmax and rmax for at each index
#     def trap(self, height: List[int]) -> int:
#         lmax, rmax = [height[0]], [height[len(height) - 1]] * len(height)
        
#         for i in range(1, len(height)):
#             lmax.append(max(lmax[i - 1], height[i]))

#         for i in range(len(height) - 2, -1, -1):
#             rmax[i] = max(rmax[i + 1], height[i])
            
#         water = 0
#         for i in range(len(height)):
#             water += min(lmax[i], rmax[i]) - height[i]
            
#         return water