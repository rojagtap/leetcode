class Solution:
  def letterCasePermutation(self, s: str) -> List[str]:
    permutations = [""]

    for char in s:
      for i in range(len(permutations)):
        if char.isalpha():
          if char.isupper():
            permutations.append(permutations[i] + char.lower())
          else:
            permutations.append(permutations[i] + char.upper())
        permutations[i] += char

    return permutations
        