class Solution:
    # O(log dividend), O(log dividend), increase in powers of 2
    def divide(self, dividend: int, divisor: int) -> int:
        positive = 1 if (dividend > 0 and divisor > 0) or (dividend < 0 and divisor < 0) else 0
        dividend, divisor = abs(dividend), abs(divisor)
        
        MAX = 2 ** 31 - 1
        HALF = 2 ** 30
        
        if divisor == 1:
            return min(MAX, dividend) if positive else -min(MAX + 1, dividend)
        elif divisor == 2:
            return dividend >> 1 if positive else -(dividend >> 1)
        
        quotient = 0
        
        div = divisor
        two = 1
        powers = [(div, two)]
        while div <= HALF and dividend >= (div + div):
            two <<= 1
            div <<= 1
            powers.append((div, two))
            
        while dividend >= divisor:
            div, power = powers.pop()
            
            if dividend >= div:
                quotient += power
                dividend -= div
        
        return min(MAX, quotient) if positive else -min(MAX + 1, quotient)
    
        
#     O(dividend), O(1), repeated subtraction TLE
#     def divide(self, dividend: int, divisor: int) -> int:
#         MAX = (2 ** 31) - 1
#         dividend_sign = -1 if dividend < 0 else 1
#         divisor_sign = -1 if divisor < 0 else 1
#         sign = dividend_sign * divisor_sign
        
#         quotient = 0
#         dividend, divisor = abs(dividend), abs(divisor)
        
#         if divisor == 1:
#             if sign < 0:
#                 return -min(MAX + 1, dividend)
#             else:
#                 return min(MAX, dividend) 
        
#         while True:
#             dividend -= divisor
            
#             if dividend < 0:
#                 return sign * quotient
            
#             if quotient == MAX:
#                 break
#             if dividend == 0:
#                 return sign * (quotient + 1)
#             else:
#                 quotient += 1
                
#         if quotient == MAX and dividend == 0:
#             if sign < 1:
#                 return -(quotient + 1)
#             else:
#                 return quotient
#         else:
#             return sign * MAX
