class Solution:
    '''
    Fast exponentiation
    
    res = x * x * x * x * ... * x * x * x * x       [n times]
    halfpower = x * x * x * x * ...                 [n / 2 times]
    Do this recusrsively
    
    res = halfpower * halfpower
    if n is odd,
    res = halfpower * halfpower * x
    '''
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