class Solution:
    # O(2n), O(n), backtracking + memoization
    def rob(self, nums: List[int]) -> int:
        @lru_cache(maxsize=None)
        def pick(start, end):
            if start <= end:
                money = nums[start]
                if start == 0:
                    maxmoney = money + pick(start + 2, end - 1)
                else:
                    maxmoney = money + pick(start + 2, end)

                return max(maxmoney, pick(start + 1, end))
            else:
                return 0
        
        
        return pick(0, len(nums) - 1)