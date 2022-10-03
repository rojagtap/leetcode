class Solution:
    # Basic division
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        whole = '0'
        if numerator == 0:
            return whole
        
        negative = ((numerator ^ denominator) < 0)
        numerator, denominator = abs(numerator), abs(denominator)
        
        if numerator >= denominator:
            whole = str(numerator // denominator)
            numerator %= denominator
            
        seen = dict()
        decimal = list()
        while numerator != 0:
            if numerator in seen:
                decimal.insert(seen[numerator], '(')
                decimal.append(')')
                break
                
            seen[numerator] = len(decimal)
            numerator *= 10
            quotient = str(numerator // denominator)
            decimal.append(quotient)
            numerator %= denominator
            
        if negative:
            whole = '-' + whole
        
        return whole + '.' + ''.join(decimal) if decimal else whole