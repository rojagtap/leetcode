class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        stacks = []
        for c in s:
            if c == '#':
                if stacks:
                    stacks.pop()
            else:
                stacks.append(c)
                
        stackt = []
        for c in t:
            if c == '#':
                if stackt:
                    stackt.pop()
            else:
                stackt.append(c)
                
        return stacks == stackt