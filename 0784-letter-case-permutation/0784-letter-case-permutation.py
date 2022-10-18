class Solution:
    # O(2n), O(2n)
    def letterCasePermutation(self, s: str) -> List[str]:
        @lru_cache(maxsize=None)
        def permutate(curr):
            if not rem:
                permutations.append(curr)
            else:
                char = rem.popleft()
                permutate(curr + char)

                if char.isalpha():
                    permutate(curr + char.swapcase())
                
                rem.appendleft(char)
        
        permutations = []
        rem = deque(s)
        
        permutate("")
        
        return permutations