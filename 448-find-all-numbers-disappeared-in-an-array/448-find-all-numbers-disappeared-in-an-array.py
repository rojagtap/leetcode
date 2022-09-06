class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        count = 0
        missing = []
        hash = set(nums)
        nmissing = len(nums) - len(hash)
        
        for num in range(1, len(nums) + 1):
            if num not in hash:
                count += 1
                missing.append(num)
                if count == nmissing:
                    return missing
                