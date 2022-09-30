class Solution:
    def letterCombinations(self, digits: str) -> List[str]:   
        if not digits:
            return ""
        
        mapping = {
            "2": "abc",
            "3": "def",
            "4": "ghi",
            "5": "jkl",
            "6": "mno",
            "7": "pqrs",
            "8": "tuv",
            "9": "wxyz"
        }
                    
        combinations = list(mapping[digits[0]])
        
        for i in range(1, len(digits)):
            diff = len(combinations)
            combinations *= len(mapping[digits[i]])
            for j in range(len(mapping[digits[i]])):
                c = mapping[digits[i]][j]
                start = j * diff
                end = start + diff
                for k in range(start, end):
                    combinations[k] += c
                
        return combinations
        
        
        
        