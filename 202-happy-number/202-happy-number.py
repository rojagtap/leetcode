class Solution:
    def isHappy(self, n: int) -> bool:
        slow, fast = n, n
        
        while fast != 1:
            slow = self.square_sum(slow)
            fast = self.square_sum(self.square_sum(fast))
            
            if slow == fast:
                break
            
        return fast == 1
        
        
    def square_sum(self, n):
        s = 0
        while n:
            digit = n % 10
            s += digit * digit
            n //= 10
            
        return s