class Solution:
    # O(2n), O(n), backtracking
    def generateAbbreviations(self, word: str) -> List[str]:
        def permutate(abbr, idx, count):
            if idx == len(word):
                if count != 0:
                    abbr += str(count)
                
                abbrevations.append(abbr)
            else:
                permutate(abbr, idx + 1, count + 1)
                
                if count != 0:
                    abbr += str(count)
                    
                abbr += word[idx]
                permutate(abbr, idx + 1, 0)
                
        abbrevations = []
        permutate("", 0, 0)
        
        return abbrevations