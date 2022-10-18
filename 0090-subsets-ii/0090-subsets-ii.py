class Solution:
    # O(2n), O(2n)
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        
        subsets, start, end = [[]], 0, 0
        for i in range(len(nums)):
            if i == 0 or nums[i] != nums[i - 1]:
                start = 0
            else:
                start = end
                
            end = len(subsets)
            for j in range(start, end):
                subsets.append(subsets[j] + [nums[i]])
            
        return subsets