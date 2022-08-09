import math

class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        elif x == 0:
            return True
        else:
            digits = int(math.log10(x)) + 1
            power = digits - 1
            factor = 10

            for i in range(digits // 2):
                if x // (10 ** power) != x % factor:
                    return False
                x = x % (10 ** power)
                x = x // factor 
                power -= 2

            return True