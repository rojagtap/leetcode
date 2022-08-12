class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        length = len(nums)
        i = 0
        
        while i < length - 1:
            j = i + 1
            while j < length and nums[j] == nums[i]:
                j += 1
                          
            i += 1

            nums[i:] = nums[j:]
            length -= (j - i)
            
        
        return length
            