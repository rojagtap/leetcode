class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
      permutations = []
      def perms(nums, curr):
        if len(nums) == 1:
          permutations.append(curr + [next(iter(nums))])
          return

        for num in set(nums):
          nums.remove(num)
          curr.append(num)
          perms(nums, curr)
          curr.pop()
          nums.add(num)

      perms(set(nums), [])
      return permutations