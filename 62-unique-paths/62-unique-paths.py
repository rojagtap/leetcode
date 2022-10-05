class Solution:
    # O(2^(m + n - 2)), O(m + n - 2)
    def uniquePaths(self, m: int, n: int) -> int:
        @lru_cache(maxsize=None)
        def nCr(n, r):
            if r == 1:
                return n
            elif n == r or r == 0:
                return 1
            else:
                return nCr(n - 1, r - 1) + nCr(n - 1, r)
            
        return nCr(m + n - 2, min(m, n) - 1)
        
    