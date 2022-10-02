class Solution:
    # O(n), O(1), Dutch national flag problem
    def sortColors(self, nums: List[int]) -> None:
        l, mid = 0, 0
        r = len(nums) - 1
        
        while mid <= r:
            if nums[mid] == 0:
                nums[l], nums[mid] = nums[mid], nums[l]
                l += 1
                mid += 1
            elif nums[mid] == 1:
                mid += 1
            else:
                nums[mid], nums[r] = nums[r], nums[mid]
                r -= 1