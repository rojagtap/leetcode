class Solution:
    def findAllConcatenatedWordsInADict(self, words: List[str]) -> List[str]:
        def is_concat(word):
            for i in range(1, len(word)):
                left, right = word[:i], word[i:]
                if left in wordset and (right in wordset or is_concat(right)):
                    return True
            
            return False
        
        wordset = set(words)
        
        concatenated_words = []
        for word in words:
            if is_concat(word):
                concatenated_words.append(word)
                
        return concatenated_words