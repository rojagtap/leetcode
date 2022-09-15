class Solution:
    # O(logn), O(1), binary search
    def mySqrt(self, x: int) -> int:
        l, r = 0, x
        
        while l <= r:
            mid = (l + r) // 2
            
            root = mid * mid
            if root < x:
                if (mid + 1) * (mid + 1) > x:
                    return mid
                l = mid + 1
            elif root > x:
                r = mid - 1
            else:
                return mid
