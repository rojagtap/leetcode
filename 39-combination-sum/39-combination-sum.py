class Solution:
    # O(n^(target/min)), O(target/min), backtracking
    # Look at the execution flow as a tree. The height of the tree is at most target/min because the deepest recursion will be for min element t times until it sums to target or exceeds
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        def backtrack(i, target):
            if target > 0:
                while i < len(candidates) and target - candidates[i] >= 0:
                    nums.append(candidates[i])
                    backtrack(i, target - candidates[i])
                    nums.pop()
                    
                    i += 1
            elif target < 0:
                return
            else:
                combinations.append(nums[:])
        
        candidates.sort()
        
        nums = []
        combinations = []
        
        backtrack(0, target)
        
        return combinations