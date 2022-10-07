class Solution:
    # O(9!), O(9!), backtracking
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        if n > 45:
            return []
        elif n == 45:
            return [[1, 2, 3, 4, 5, 6, 7, 8, 9]]
        
        def backtrack(i, total):
            if len(nums) == k:
                if total == 0:
                    combinations.append(nums[:])
            else:
                while i <= 9 and total - i >= 0:
                    nums.append(i)
                    backtrack(i + 1, total - i)
                    nums.pop()
                    i += 1
                
        nums = []
        combinations = []
        
        backtrack(1, n)
        return combinations