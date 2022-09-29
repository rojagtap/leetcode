class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        
        matches = 0
        freq = Counter(t)
        for c in s:
            if c in freq:
                freq[c] -= 1
                if freq[c] == 0:
                    matches += 1
            else:
                return False
        
        return matches == len(freq)