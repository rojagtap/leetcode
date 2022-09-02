class Solution:
    def platesBetweenCandles(self, s: str, queries: List[List[int]]) -> List[int]:
        plates = []
        
        count = 0
        runningcount = []
        candles = []
        
        for i in range(len(s)):
            c = s[i]
            if c == '*':
                count += 1
            
            runningcount.append(count)
            
            if c == '|':
                candles.append(i)
                
        for q in queries:
            left = self.binary_search_left(q[0], candles)
            right = self.binary_search_right(q[1], candles)
            
            if left != -1 and right != -1 and left <= right:
                plates.append(runningcount[right] - runningcount[left])
            else:
                plates.append(0)
                
        return plates
        
    
    
    def binary_search_left(self, index, candles):
        l, r = 0, len(candles) - 1
        candle = -1
        
        while l <= r:
            mid = (l + r) // 2
            if candles[mid] > index:
                candle = candles[mid]
                r = mid - 1
            elif candles[mid] < index:
                l = mid + 1
            else:
                return candles[mid]
            
        return candle
    
    
    def binary_search_right(self, index, candles):
        l, r = 0, len(candles) - 1
        candle = -1
        
        while l <= r:
            mid = (l + r) // 2
            if candles[mid] < index:
                candle = candles[mid]
                l = mid + 1
            elif candles[mid] > index:
                r = mid - 1
            else:
                return candles[mid]
            
        return candle