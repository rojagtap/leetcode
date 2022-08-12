class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        result = []
        nums.sort()
        length = len(nums)
        
        for i in range(length - 3):
            if i != 0 and nums[i] == nums[i - 1]:
                continue
            for j in range(i + 1, length - 2):
                if j != i + 1 and nums[j] == nums[j - 1]:
                    continue
                l = j + 1
                r = length - 1
                while l < r:
                    four_sum = nums[i] + nums[j] + nums[l] + nums[r]
                    if four_sum > target:
                        r -= 1
                    elif four_sum < target:
                        l += 1
                    else:
                        result.append([nums[i], nums[j], nums[l], nums[r]])
                        while (r - 1) >= 0 and nums[r - 1] == nums[r]:
                            r -= 1
                        r -= 1
        return result