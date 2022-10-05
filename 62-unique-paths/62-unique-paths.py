class Solution:    
    def uniquePaths(self, m: int, n: int) -> int:
        @lru_cache(maxsize=None)
        def nCr(n, r):
            if r == 1:
                return n
            elif n == r or r == 0:
                return 1
            else:
                return nCr(n - 1, r - 1) + nCr(n - 1, r)
            
        return nCr(m + n - 2, m - 1)    # or nCr(m + n - 2, n - 1)
        
    