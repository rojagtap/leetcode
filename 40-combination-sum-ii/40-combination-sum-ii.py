class Solution:
    # O(n!), O(n!), backtracking
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        total = sum(candidates)
        if target > total:
            return []
        elif target == total:
            return [candidates]
        
        def backtrack(start, target):
            if target > 0:
                i = start
                while i < len(candidates) and target - candidates[i] >= 0:
                    if i > start and candidates[i] == candidates[i - 1]:
                        i += 1
                        continue
                    
                    nums.append(candidates[i])
                    backtrack(i + 1, target - candidates[i])
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