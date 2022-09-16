from collections import Counter

class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        subs = []
        wordlen = len(words[0])
        
        freq = dict()
        for start in range(wordlen):
            freq.clear()
            freq = Counter(words)
            
            matches = 0
            left = start
            for right in range(start, len(s), wordlen):
                if right + wordlen > len(s):
                    break

                currword = s[right: right + wordlen]

                if currword in freq:
                    freq[currword] -= 1
                    if freq[currword] == 0:
                        matches += 1

                while left <= right and freq.get(currword, -1) < 0:
                    leftword = s[left: left + wordlen]
                    if leftword in freq:
                        if freq[leftword] == 0:
                            matches -= 1

                        freq[leftword] += 1

                    left += wordlen

                if matches == len(freq):
                    subs.append(left)
                
        return subs