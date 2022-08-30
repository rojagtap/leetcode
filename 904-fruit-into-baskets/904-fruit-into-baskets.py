class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        freq = dict()
        distinct = 0
        maxfruits = 0
        
        l = 0
        for r in range(len(fruits)):
            if freq.get(fruits[r], 0) == 0:
                distinct += 1
            
            freq[fruits[r]] = freq.get(fruits[r], 0) + 1
            
            while distinct > 2:
                freq[fruits[l]] -= 1
                if freq[fruits[l]] == 0:
                    distinct -= 1
                    
                l += 1
                
            maxfruits = max(maxfruits, r - l + 1)
            
        return maxfruits