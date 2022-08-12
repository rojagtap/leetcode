class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        length = len(nums)
        if not val in nums:
            return length
        
        nums.sort()
        idx = nums.index(val)
        count = 0
        i = idx
        
        while i < length and nums[i] == val:
            count += 1
            i += 1

        nums[idx:] = nums[i:]
        length -= count
        
        return length