class Solution:
    def isValid(self, s: str) -> bool:
        opening = {"(", "[", "{"}
        closing = {")", "]", "}"}
        mapping = {
            "(": ")",
            "[": "]",
            "{": "}"
        }
        stack = []
        
        for parentheses in s:
            if parentheses in opening:
                stack.append(parentheses)
            elif parentheses in closing:
                if stack and mapping[stack[-1]] == parentheses:
                    stack.pop()
                else:
                    return False
            else:
                return False
        
        if stack:
            return False
        return True