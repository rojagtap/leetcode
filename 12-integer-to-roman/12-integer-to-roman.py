from collections import deque

class Solution:
    def __init__(self):
        self.keys = [1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000]
        self.values = {
            1: 'I',
            4: "IV",
            5: 'V',
            9: "IX",
            10: 'X',
            40: "XL",
            50: 'L',
            90: "XC",
            100: 'C',
            400: "CD",
            500: 'D',
            900: "CM",
            1000: 'M'
        }
    
    def intToRoman(self, num: int) -> str:
        factor = 1
        queue = deque()
        while num:
            queue.appendleft((num % 10) * factor)
            num //= 10
            factor *= 10
            
        roman = ""
        for digit in queue:
            roman += self.convert(digit)
        
        return roman
    
    
    def convert(self, num):
        if num == 0:
            return ''
        
        i = -1
        while (i + 1) < len(self.keys) and num >= self.keys[i + 1]:
            i += 1
            
        conversion = self.values[self.keys[i]] * (num // self.keys[i])
        if num % self.keys[i]:
            return conversion + self.convert(num - self.keys[i])
        else:
            return conversion
        