class Solution:
    # O(n), O(1)
    # cyclic sort
    def firstMissingPositive(self, nums: List[int]) -> int:
        for i in range(len(nums)):
            while 1 <= nums[i] <= len(nums) and nums[i] != i + 1:
                j = nums[i] - 1
                if nums[i] == nums[j]:
                    break
                
                nums[i], nums[j] = nums[j], nums[i]
                
        for i in range(len(nums)):
            if nums[i] != i + 1:
                return i + 1
            
        return len(nums) + 1