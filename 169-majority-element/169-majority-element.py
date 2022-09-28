class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        freq = dict()
        majority, frequency = 0, -inf
        
        for i in range(len(nums)):
            freq[nums[i]] = freq.get(nums[i], 0) + 1
            if freq[nums[i]] > frequency:
                frequency = freq[nums[i]]
                majority = nums[i]
            
        return majority