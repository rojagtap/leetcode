class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        if len(word) == 1:
            return True
                
        if word[0].isupper():
            if word[1].isupper():
                return self.allcaps(word[2:])
            
        return self.allsmalls(word[1:])
            
        
    def allcaps(self, word):
        for l in word:
            if l.islower():
                return False
            
        return True
    
    def allsmalls(self, word):
        for l in word:
            if l.isupper():
                return False
            
        return True
    