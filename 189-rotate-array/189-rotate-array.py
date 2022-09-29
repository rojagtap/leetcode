class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        
        queue = deque(nums)
        queue.rotate(k % len(nums))
        
        for i in range(len(nums)):
            nums[i] = queue[i]