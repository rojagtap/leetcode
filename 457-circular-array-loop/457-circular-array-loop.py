import math

class Solution:
    def circularArrayLoop(self, arr: List[int]) -> bool:        
        for start in range(len(arr)):
            slow, fast = start, start
            sign = math.copysign(1, arr[start])
            flag = True
            
            while True:
                fast = (fast + arr[fast]) % len(arr)
                slow = (slow + arr[slow]) % len(arr)
                
                if sign != math.copysign(1, arr[fast]):
                    flag = False
                    break

                if fast == (fast + arr[fast]) % len(arr):
                    flag = False
                    break
                
                fast = (fast + arr[fast]) % len(arr)
                
                if sign != math.copysign(1, arr[fast]):
                    flag = False
                    break
                
                if slow == fast:
                    break
                
            if flag:
                return True
                
        return False