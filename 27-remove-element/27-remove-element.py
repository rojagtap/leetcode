class Solution:
#    O(n), O(1), two-pointers
    def removeElement(self, nums: List[int], val: int) -> int:
        left = 0
        
        for right in range(len(nums)):
            if nums[right] != val:
                nums[left], nums[right] = nums[right], nums[left]
                left += 1
            
        return left
        
        
#     O(nlogn), O(1), sorting + two-pointers
#     def removeElement(self, nums: List[int], val: int) -> int:
#         length = len(nums)
#         if not val in nums:
#             return length
        
#         nums.sort()
#         idx = nums.index(val)
#         count = 0
#         i = idx
        
#         while i < length and nums[i] == val:
#             count += 1
#             i += 1

#         nums[idx:] = nums[i:]
#         length -= count
        
#         return length