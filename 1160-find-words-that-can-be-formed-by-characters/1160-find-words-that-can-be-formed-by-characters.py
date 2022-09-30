class Solution:
    # O(k + nm), O(nm) where n is the number of words, k is the total number of characters in words, m is the number of distinct characters in chars
    # nm because for each word we are making a copy of the chars counter which is m time and m space
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