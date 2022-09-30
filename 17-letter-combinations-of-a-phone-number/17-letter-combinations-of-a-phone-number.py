class Solution:
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
    
#     O(n), O(n) where n is the total number of combinations possible
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return ""
                            
        combinations = list(self.mapping[digits[0]])
        
        for i in range(1, len(digits)):
            diff = len(combinations)
            combinations *= len(self.mapping[digits[i]])
            for j in range(len(self.mapping[digits[i]])):
                c = self.mapping[digits[i]][j]
                start = j * diff
                end = start + diff
                for k in range(start, end):
                    combinations[k] += c
                
        return combinations
        
#     Using library
#     def letterCombinations(self, digits: str) -> List[str]:
#         if not digits:
#             return ""
        
#         chars = [self.mapping[digit] for digit in digits]
#         combinations = []
#         for product in itertools.product(*chars):
#             combinations.append("".join(product))
            
#         return combinations

        
        