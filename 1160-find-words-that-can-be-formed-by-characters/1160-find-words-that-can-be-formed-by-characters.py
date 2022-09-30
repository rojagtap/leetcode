class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        def good(word, chars):
            for char in word:
                if chars.get(char, 0) == 0:
                    return False
                chars[char] -= 1
                
            return True
        
        freq = Counter(chars)
        
        length = 0
        for word in words:
            if good(word, freq.copy()):
                length += len(word)
        
        return length