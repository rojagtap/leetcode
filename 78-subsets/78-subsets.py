class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
      subsets = [[]]
      for num in nums:
          for i in range(len(subsets)):
            subsets.append(subsets[i] + [num])
            
      return subsets