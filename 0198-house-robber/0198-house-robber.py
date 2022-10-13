class Solution:
    
    # O(2^n) ~ O(n), O(n), backtracking + memoization
    def rob(self, houses: List[int]) -> int:
        @lru_cache(maxsize=None)
        def pick(start, end):
            return max(houses[start] + pick(start + 2, end), pick(start + 1, end)) if start <= end else 0
        
        return pick(0, len(houses) - 1)
