class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        freq = dict()
        for p in s1:
            freq[p] = freq.get(p, 0) + 1
        
        l = 0
        for r in range(len(s2)):
            if s2[r] in freq:
                freq[s2[r]] -= 1
                
            if r >= len(s1) - 1:
                if self.allzero(freq):
                    return True
                
                if s2[l] in freq:
                    freq[s2[l]] +=  1
                    
                l += 1
                
        return self.allzero(freq)
    
    
    def allzero(self, freq):
        for k in freq:
            if freq[k] != 0:
                return False
            
        return True