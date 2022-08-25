class Solution:
    def minWindow(self, s: str, t: str) -> str:
        matches = 0
        minlen = math.inf

        freq = dict()
        for c in t:
            freq[c] = freq.get(c, 0) + 1

        start = 0
        end = 0
        
        l = 0
        for r in range(len(s)):
            if s[r] in freq:
                freq[s[r]] -= 1
                matches += (freq[s[r]] == 0)

            if matches == len(freq):
                while l < len(s):
                    if s[l] in freq:
                        if freq[s[l]] == 0:
                            break
                        
                        freq[s[l]] += 1

                    l += 1
                
                if (r - l + 1) < minlen:
                    start = l
                    end = r
                    minlen = r - l + 1

        if matches == len(freq):
            return s[start: end + 1]
        else:
            return ""
