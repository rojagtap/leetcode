class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        result = []
        nums.sort()
        length = len(nums)

        for i in range(length - 2):
            if i != 0 and nums[i] == nums[i - 1]:
                continue
            l = i + 1
            r = length - 1
            while l < r:
                if (nums[l] + nums[r]) < -nums[i]:
                    l += 1
                elif (nums[l] + nums[r]) > -nums[i]:
                    r -= 1
                else:
                    result.append([nums[i], nums[l], nums[r]])
                    while (r - 1) >= 0 and nums[r - 1] == nums[r]:
                        r -= 1
                    r -= 1
                        
        return result