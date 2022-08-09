class Solution:
    def reverse(self, x: int) -> int:
        min_int = -2 ** 31
        max_int = -1 * min_int - 1
        
        if x < 0:
            negative = True
            x = -x
        else:
            negative = False
        
        factor = 10
        reverse = 0
        while (x > 0):
            reverse = reverse * factor + (x % 10)
            x = x // 10
            
        if negative:
            reverse = -1 * reverse
        
        if reverse > max_int or reverse < min_int:
            return 0
        else:
            return reverse