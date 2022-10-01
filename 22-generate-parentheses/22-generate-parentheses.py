class Solution:
    # O(2n), O(2n) approx., O(Catalan number) i.e. O(4n/sqrt(n))
    def generateParenthesis(self, n: int) -> List[str]:
        def generate(parantheses, opencount, closedcount):
            if opencount == n and closedcount == n:
                combinations.append(parantheses)
            else:
                if opencount < n:
                    generate(parantheses + '(', opencount + 1, closedcount)
                
                if closedcount < n and opencount > closedcount:
                    generate(parantheses + ')', opencount, closedcount + 1)
                    
        combinations = []
        generate("", 0, 0)
        
        return combinations