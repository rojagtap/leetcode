class Solution:
    # backtracking with memoization, dp
    # O(n * u), O(u) where u is the number of unique targets remaining vs the corresp count returned
    def combinationSum4(self, candidates: List[int], target: int) -> int:
        @lru_cache(maxsize = None)
        def backtrack(target):
            count = 0            
            if target > 0:
                i = 0
                while i < len(candidates) and target - candidates[i] >= 0:
                    count += backtrack(target - candidates[i])
                    i += 1
                    
                return count
            else:
                return 1
        
        candidates.sort()
        
        return backtrack(target)