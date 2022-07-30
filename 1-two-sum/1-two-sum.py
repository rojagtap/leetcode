class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hash = dict()
        
        for i in range(len(nums)):
            if hash.get(target - nums[i]) is None:
                hash[nums[i]] = i
            else:
                return [i, hash.get(target - nums[i])]
            
        return []
        