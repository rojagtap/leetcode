class Solution:
    def checkPossibility(self, nums: List[int]) -> bool:
        count = None
        for i in range(len(nums) - 1):
            if nums[i] > nums[i + 1]:
                if count is not None:
                    return False
                
                count = i
        
        return count is None or count == 0 or count == len(nums) - 2 or nums[count - 1] <= nums[count + 1] or nums[count] <= nums[count + 2]