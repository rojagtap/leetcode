class Solution:
    def majorityElement(self, nums):
        count = 0
        candidate = None

        for num in nums:
            if count == 0:
                candidate = num
            count += (1 if num == candidate else -1)

        return candidate
    
#     def majorityElement(self, nums: List[int]) -> int:
#         freq = dict()
#         majority, frequency = 0, -inf
        
#         for i in range(len(nums)):
#             freq[nums[i]] = freq.get(nums[i], 0) + 1
#             if freq[nums[i]] > frequency:
#                 frequency = freq[nums[i]]
#                 majority = nums[i]
            
#         return majority