class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        count = 0
        currsum = 0
        length = len(nums)

        hashmap = {0: 1}
        
        for a in nums:
            currsum += a
            count += hashmap.get(currsum - k, 0)
            hashmap[currsum] = hashmap.get(currsum, 0) + 1

        return count