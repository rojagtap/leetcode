class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
      numsLength = len(nums)
      result = []
      permutations = deque()
      permutations.append([])
      for currentNumber in nums:
        # we will take all existing permutations and add the current number to create new permutations
        n = len(permutations)
        for _ in range(n):
          oldPermutation = permutations.popleft()
          # create a new permutation by adding the current number at every position
          for j in range(len(oldPermutation)+1):
            newPermutation = list(oldPermutation)
            newPermutation.insert(j, currentNumber)
            if len(newPermutation) == numsLength:
              result.append(newPermutation)
            else:
              permutations.append(newPermutation)

      return result