class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        res = []
        wordlen = len(words[0])
        
        freq = dict()
        for word in words:
            freq[word] = freq.get(word, 0) + 1
            
        for l in range(wordlen):
            start = l
            seen = dict()
            total = 0
            for r in range(l, len(s), wordlen):
                if (r + wordlen) > len(s):
                    break
                    
                word = s[r: r + wordlen]
                if word in freq:
                    seen[word] = seen.get(word, 0) + 1
                    total += 1
                    
                    while seen[word] > freq[word]:
                        leftmost = s[start: start + wordlen]
                        seen[leftmost] -= 1
                        start += wordlen
                        total -= 1
                else:
                    seen.clear()
                    total = 0
                    start = r + wordlen
                
                if total == len(words):
                    res.append(start)
                    leftmost = s[start: start + wordlen]
                    seen[leftmost] -= 1
                    start += wordlen
                    total -= 1

        return res
