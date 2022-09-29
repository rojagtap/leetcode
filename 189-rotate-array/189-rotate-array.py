class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        def reverse(i, j):
            nonlocal nums
            
            while i < j:
                nums[i], nums[j] = nums[j], nums[i]
                i += 1
                j -= 1
        
        n = len(nums)
        k = k % n
        reverse(0, n - 1)
        reverse(0, k - 1)
        reverse(k, n - 1)
        
#     def rotate(self, nums: List[int], k: int) -> None:
#         """
#         Do not return anything, modify nums in-place instead.
#         """
        
#         queue = deque(nums)
#         queue.rotate(k % len(nums))
        
#         for i in range(len(nums)):
#             nums[i] = queue[i]