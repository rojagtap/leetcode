class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        res = set()
        matches = 0

        freq = dict()
        for c in p:
            freq[c] = freq.get(c, 0) + 1

        l = 0
        for r in range(len(s)):
            if s[r] in freq:
                freq[s[r]] -= 1
                matches += (freq[s[r]] == 0)

            if r >= len(p) - 1:
                if matches == len(freq):
                    res.add(l)

                if s[l] in freq:
                    if freq[s[l]] == 0:
                        matches -= 1
                    freq[s[l]] += 1

                l += 1

        if matches == len(freq):
            res.add(l)

        return list(res)
