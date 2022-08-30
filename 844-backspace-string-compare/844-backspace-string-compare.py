class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        stacks = []
        for c in s:
            if c != '#':
                stacks.append(c)                    
            elif stacks:
                stacks.pop()
                
                
        stackt = []
        for c in t:
            if c != '#':
                stackt.append(c)
            elif stackt:
                stackt.pop()
                
                
        return stacks == stackt