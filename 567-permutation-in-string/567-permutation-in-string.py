import collections

class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        matches = 0
        
        freq = collections.Counter(s1)
        
        l = 0
        for r in range(len(s2)):
            if s2[r] in freq:
                freq[s2[r]] -= 1
                matches += (freq[s2[r]] == 0)
            else:
                while l < r + 1:
                    if s2[l] in freq:
                        if freq[s2[l]] == 0:
                            matches -= 1
                        freq[s2[l]] +=  1
                    l += 1
                
            if r - l + 1 >= len(s1):
                if matches == len(freq):
                    return True
                
                if s2[l] in freq:
                    if freq[s2[l]] == 0:
                        matches -= 1
                    freq[s2[l]] +=  1
                    
                l += 1

        return False