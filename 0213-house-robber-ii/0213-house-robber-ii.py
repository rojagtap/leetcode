class Solution:
    # O(2n), O(n), backtracking + memoization
    def rob(self, nums: List[int]) -> int:
        @lru_cache(maxsize=None)
        def pick(start, end):
            if start <= end:
                money = nums[start]
                offset = 0
                if start == 0:
                    offset = 1

                return max(money + pick(start + 2, end - offset), pick(start + 1, end))
            else:
                return 0
        
        
        return pick(0, len(nums) - 1)