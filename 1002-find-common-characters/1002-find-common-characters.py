class Solution:
    def commonChars(self, words: List[str]) -> List[str]:
        freq = dict()
        
        reference = words.pop()
        for letter in reference:
            freq[letter] = freq.get(letter, 0) + 1
        
        for word in words:
            for letter in freq:
                if letter in word:
                    count = word.count(letter)
                    if count < freq[letter]:
                        freq[letter] = count
                else:
                    freq[letter] = 0
        
        repeat = []
        for letter, count in freq.items():
            repeat.extend([letter] * count)
                
        return repeat