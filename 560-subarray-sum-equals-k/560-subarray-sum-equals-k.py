class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        count = 0
        currsum = 0
        length = len(nums)

        hashmap = {0: 1}
        
        for a in nums:
            currsum += a
            if hashmap.get(currsum - k):
                count += hashmap[currsum - k]            
                
            hashmap[currsum] = hashmap.get(currsum, 0) + 1

        return count