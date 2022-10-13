class Solution:
    # O(2n), O(n), backtracking + memoization
    def rob(self, nums: List[int]) -> int:
        @lru_cache(maxsize=None)
        def pick(money, start, end):
            if start > end:
                return money
            else:
                if start == 0:
                    maxmoney = pick(money + nums[start], start + 2, end - 1)
                else:
                    maxmoney = pick(money + nums[start], start + 2, end)

                return max(maxmoney, pick(money, start + 1, end))
                    
        
        return pick(0, 0, len(nums) - 1)