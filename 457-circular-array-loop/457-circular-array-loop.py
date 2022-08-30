import math

class Solution:
    def circularArrayLoop(self, arr: List[int]) -> bool:        
        for start in range(len(arr)):
            slow, fast = start, start
            sign = math.copysign(1, arr[start])
            
            while True:
                fast = (fast + arr[fast]) % len(arr)
                
                if sign != math.copysign(1, arr[fast]):
                    break

                if fast == (fast + arr[fast]) % len(arr):
                    break
                
                slow = (slow + arr[slow]) % len(arr)
                fast = (fast + arr[fast]) % len(arr)
                
                if sign != math.copysign(1, arr[fast]):
                    break
                
                if slow == fast:
                    return True
                                
        return False