class Solution:
#    O(n), O(1)
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        i = 0
        while i < len(nums):
            j = nums[i] - 1
            if nums[i] != i + 1:
                nums[i], nums[j] = nums[j], nums[i]
                i += (nums[i] == nums[j])
            else:
                i += 1
        
        missing = []
        for i in range(len(nums)):
            if nums[i] != i + 1:
                missing.append(i + 1)
                
        return missing
        
        
#     O(n), O(n)
#     def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
#         count = 0
#         missing = []
#         hash = set(nums)
#         nmissing = len(nums) - len(hash)
        
#         for num in range(1, len(nums) + 1):
#             if num not in hash:
#                 count += 1
#                 missing.append(num)
#                 if count == nmissing:
#                     return missing
                