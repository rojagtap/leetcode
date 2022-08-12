class Solution:
    #   O(n)
    def maxOperations(self, nums: List[int], k: int) -> int:
        hash = dict()
        count = 0
        
        for num in nums:
            if hash.get(k - num, 0):
                count += 1
                hash[k - num] = hash[k - num] - 1
            else:
                hash[num] = hash.get(num, 0) + 1
                        
        return count
    
    
#     O(nlogn) because sorting
#     def maxOperations(self, nums: List[int], k: int) -> int:
#         nums.sort()
#         length = len(nums)
#         count = 0
#         i, j = 0, length - 1
        
#         while i < j:
#             if i < length and nums[i] == 0:
#                 i += 1
#             elif j >= 0 and nums[j] == 0:
#                 j -= 1
#             else:
#                 currsum = nums[i] + nums[j]
#                 if currsum < k:
#                     i += 1
#                 elif currsum > k:
#                     j -= 1
#                 else:
#                     count += 1
#                     nums[i] = 0
#                     nums[j] = 0
                    
#         return count