class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        res = []
        wordlen = len(words[0])
        matches = 0

        freq = dict()
        for word in words:
            freq[word] = freq.get(word, 0) + 1

        l, r = 0, wordlen
        while r <= len(s):
            word = s[r - wordlen: r]

            if word in freq:
                seen = {word: 1}
                total = 1
                r_ = r + wordlen

                while r_ <= len(s):
                    word_ = s[r_ - wordlen: r_]

                    if word_ in freq:
                        seen[word_] = seen.get(word_, 0) + 1
                        total += 1
                        r_ += wordlen
                        
                        if seen[word_] > freq[word_]:
                            l += 1
                            r = l + wordlen
                            break
                    else:
                        if total == len(words):
                            res.append(l)
                        l += 1
                        r = l + wordlen
                        break

                    if total == len(words):
                        res.append(l)
                        l += 1
                        r = l + wordlen
                        break
                else:
                    if total == len(words):
                        res.append(l)
                    l += 1
                    r = l + wordlen
            else:
                l += 1
                r = l + wordlen

        return res
