class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        matches = 0
        
        freq = dict()
        for p in s1:
            freq[p] = freq.get(p, 0) + 1
        
        l = 0
        for r in range(len(s2)):
            if s2[r] in freq:
                freq[s2[r]] -= 1
                matches += (freq[s2[r]] == 0)
                
            if r >= len(s1) - 1:
                if matches == len(freq):
                    return True
                
                if s2[l] in freq:
                    if freq[s2[l]] == 0:
                        matches -= 1
                    freq[s2[l]] +=  1
                    
                l += 1

        return matches == len(freq)