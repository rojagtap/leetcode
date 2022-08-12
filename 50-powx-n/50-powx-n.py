class Solution:
    # Fast exponentiation
    def myPow(self, x: float, n: int) -> float:
        res = self.power(x, abs(n))
        
        if n < 0:
            return 1.0 / res
        else:
            return res
    
    
    def power(self, x, n):
        if n == 0:
            return 1
        elif n == 1:
            return x
        else:
            halfpower = self.power(x, n // 2)
            res = halfpower * halfpower
            
            if n & 1:
                return res * x
            else:
                return res