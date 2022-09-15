class Solution:
    def isPerfectSquare(self, x: int) -> bool:
        l, r = 0, x
        
        while l <= r:
            mid = (l + r) // 2
            
            root = mid * mid
            if root < x:
                if (mid + 1) * (mid + 1) > x:
                    return False
                
                l = mid + 1
            elif root > x:
                r = mid - 1
            else:
                return True
