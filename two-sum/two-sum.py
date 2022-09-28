class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hash = dict()
        
        for i, num in enumerate(nums):
            if hash.get(target - num) is None:
                hash[num] = i
            else:
                return [i, hash.get(target - num)]
            
        return []
        